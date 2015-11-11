#-*- coding:utf-8 -*-
#!/usr/bin/env python

import os
import uuid
import threading
import subprocess
from time import ctime,sleep

# ����sqlalchemyģ��
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from sqlalchemy.orm.exc import NoResultFound
from sqlalchemy.orm.exc import MultipleResultsFound
# from sqlalchemy.ext.declarative import declarative_base

from cbm import CbmService
from cbm.ttypes import *

import SQL
import CbmUtil
import ThriftServerHelper
import SQLServerHelper

#��ʼ��sqlalchemy������mysql���ݿ�
def init_sqlalchemy():
    #����mysql���ݲ�����session�Ự
    # engine = create_engine("mysql+pymysql:# root:@localhost/cbm?charset=utf-8")
    #echo�������ڵ���!!!
    engine = create_engine("mysql+pymysql://root:@localhost/cbm",echo=True)
    Session = sessionmaker()
    Session.configure(bind=engine)
    return Session

# cad���͹��������ݻ���
POST_DATA_FROM_CAD_CACHE = {}

# �ο�:�������service(http:# blog.csdn.net/hivon/article/details/11681977)
# sqlalchemy�����ַ������(http:# www.it165.net/database/html/201404/6034.html)
# service�ӿڴ�����
class CbmServiceHandler(SQLServerHelper.SQLServiceHandler):
    def __init__(self, Session):
        self.session = Session()
        # ���mysql������������
        self.session.execute("set names 'utf8'")
        # ���û���ĳ�ʼ������
        super(CbmServiceHandler, self).__init__(self.session)

    def InitSampleMine(self, region_id, account_id, name):
        query = self.session.query(SQL.Mine).filter(SQL.Mine.mine_region_id==region_id, SQL.Mine.account_id==account_id).first()
        if query is None:
            mine = SQL.Mine()
            mine.name = 'ʾ��������-%s' % name
            mine.mine_region_id = region_id
            mine.account_id = account_id
            self.session.add(mine)
            self.session.flush()
            self.session.commit()

    def InitSampleRegion(self):
        try:
            # ���ҹ���Ա�ʻ�
            admin = self.session.query(SQL.Account).filter(SQL.Account.username=='adminx').first()
            if admin is None:
                admin = SQL.Account()
                admin.username = 'adminx'
                admin.password = '123'
                admin.comment = '��������Ա'
                self.session.add(admin)
                self.session.flush()
                self.session.commit()
                print admin.id
            # ��������ʾ������
            jincheng = self.session.query(SQL.MineRegion).filter(SQL.MineRegion.name=='����').one()
            lianghuai = self.session.query(SQL.MineRegion).filter(SQL.MineRegion.name=='����').one()
            songzao = self.session.query(SQL.MineRegion).filter(SQL.MineRegion.name=='����').one()
            # ����id���γ�ʼ��ʾ������������
            self.InitSampleMine(jincheng.id, admin.id, "����")
            self.InitSampleMine(lianghuai.id, admin.id, "����")
            self.InitSampleMine(songzao.id, admin.id, "����")
        except Exception, e:
            print e
    
    def GetOnlineAccountId(self):
        query = self.session.query(SQL.Account).join(SQL.SysInfo).first()
        if query is None:
            return -1
        else:
            return query.id

    def GetOnlineMine(self):
        mine = Mine()
        mine.id = -1

        account_id = self.GetOnlineAccountId()
        if account_id > -1:
            try:
                query = self.session.query(SQL.Mine).filter(SQL.Mine.account_id==account_id).one()
                CbmUtil.CopyAttribs(query, mine)
            except Exception, e:
                mine.id = -1
                print e
        return mine

    def VerifyMineAccount(self, username, pwd):
        print '. VerifyMineAccount'
        query = self.session.query(SQL.Account).filter(SQL.Account.username==username)
        if query.count() == 0:
            return 0  # �û���������
        elif query.count() > 1:
            return -2 # �ڲ�����(�û�����Ψһ)
        else:
            accout = query.one()
            if accout.password != pwd:
                return -1  # �������
            else:
                return 1  # �û����������ƥ��

    def GetMineRegionsOfBase(self, baseName):
        mine_regions = []
        query = self.session.query(SQL.MineRegion).join(SQL.MineBase).filter(SQL.MineBase.name==baseName).all()
        mine_regions = [region.name for region in query]
        return mine_regions

    def GetBaseByRegion(self, regionName):
        baseName = ''
        try:
            query = self.session.query(SQL.MineBase).join(SQL.MineRegion).filter(SQL.MineRegion.name==regionName).one()
            baseName = query.name
        except Exception, e:
            baseName = ''
            print e
        return baseName

    def GetSampleMineOfRegion(self, regionName):
        sample_mine = Mine()
        sample_mine.id = -1
        try:
            query = self.session.query(SQL.Mine).join(SQL.MineRegion).filter(SQL.MineRegion.name==regionName).one()
            # ͨ�ø��ƺ���
            CbmUtil.CopyAttribs(query, sample_mine)
        except Exception, e:
            sample_mine.id = -1
            print e
        return sample_mine

    def GetSampleCoalOfRegion(self, regionName):
        sample_coal = Coal()
        sample_coal.id = -1
        
        sample_mine = self.GetSampleMineOfRegion(regionName)
        if sample_mine.id > -1:
            try:
                query = self.session.query(SQL.Coal).filter(SQL.Coal.mine_id==sample_mine.id).one()
                # ͨ�ø��ƺ���
                CbmUtil.CopyAttribs(query, sample_coal)
            except Exception, e:
                sample_coal.id = -1
                print e
        return sample_coal

    def GetCoalNamesOfMine(self, mine_id):
        query = self.session.query(SQL.Coal).filter(SQL.Coal.mine_id==mine_id).all()
        return [coal.name for coal in query]

    def GetCoalIdsOfMine(self, mine_id):
        query = self.session.query(SQL.Coal).filter(SQL.Coal.mine_id==mine_id).all()
        return [coal.id for coal in query]

    def GetWorkAreasOfMine(self, mine_id):
        coal_ids = self.GetCoalIds(mine_id)
        if len(coal_ids) == 0:
            return []

        query = self.session.query(SQL.WorkArea).filter(SQL.WorkArea.coal_id.in_(coal_ids)).all()
        if len(query) == 0:
            return []

        n = len(query)
        work_areas = [WorkArea() for i in range(n)]
        for i in range(n):
            work_areas[i].id = -1
            CbmUtil.CopyAttribs(query[i], work_areas[i])
        return work_areas

    def GetWorkSurfsOfMine(self, mine_id):
        work_area_ids = self.GetWorkAreaIds(mine_id)
        if len(work_area_ids) == 0:
            return []

        query = self.session.query(SQL.WorkSurf).filter(SQL.WorkSurf.work_area_id.in_(work_area_ids)).all()
        if len(query) == 0:
            return []

        n = len(query)
        work_surfs = [WorkSurf() for i in range(n)]
        for i in range(n):
            work_surfs[i].id = -1
            CbmUtil.CopyAttribs(query[i], work_surfs[i])
        return work_surfs

    def GetDrillingSurfsOfMine(self, mine_id):
        work_area_ids = self.GetWorkAreaIds(mine_id)
        if len(work_area_ids) == 0:
            return []

        query = self.session.query(SQL.DrillingSurf).filter(SQL.DrillingSurf.work_area_id.in_(work_area_ids)).all()
        if len(query) == 0:
            return []
        
        n = len(query)
        drilling_surfs = [DrillingSurf() for i in range(n)]
        for i in range(n):
            drilling_surfs[i].id = -1
            CbmUtil.CopyAttribs(query[i], drilling_surfs[i])
        return drilling_surfs

    def GetWorkAreaIdsOfMine(self, mine_id):
        coal_ids = self.GetCoalIds(mine_id)
        if len(coal_ids) == 0:
            return []
        query = self.session.query(SQL.WorkArea).filter(SQL.WorkArea.coal_id.in_(coal_ids)).all()
        return [work_area.id for work_area in query]

    def GetWorkSurfIdsOfMine(self, mine_id):
        work_area_ids = self.GetWorkAreaIds(mine_id)
        if len(work_area_ids) == 0:
            return []
        query = self.session.query(SQL.WorkSurf).filter(SQL.WorkSurf.work_area_id.in_(work_area_ids)).all()
        return [work_surf.id for work_surf in query]

    def GetDrillingSurfIdsOfMine(self, mine_id):
        work_area_ids = self.GetWorkAreaIds(mine_id)
        if len(work_area_ids) == 0:
            return []
        query = self.session.query(SQL.DrillingSurf).filter(SQL.DrillingSurf.work_area_id.in_(work_area_ids)).all()
        return [drilling_surf.id for drilling_surf in query]

    def DifficultEval(self, coal):
        # �����������˥��ϵ�� �� ú��͸����ϵ����������
        k1 = CbmUtil.DifficultEval1(coal.decay_alpha)
        k2 = CbmUtil.DifficultEval2(coal.permeability_lambda)
        return CbmUtil.DifficultEvalHelper(k1, k2)

    def DifficultEvalString(self, coal):
        s1 = PermeabilityString(coal.permeability_k)
        s2 = EvalDifficultString(coal.eval_difficult)
        return "��ú������:%s\\n��˹������׳̶�:%s" % (s1, s2)

    def MineGasReservesW1(self, mine_id):
       query = self.session.query(SQL.Coal).filter(SQL.Coal.mine_id==mine_id, SQL.Coal.minable==1).all()
       return sum([coal.res_a1*coal.gas_x1 for coal in query])
    
    def MineGasReservesW2(self, mine_id):
        query = self.session.query(SQL.Coal).filter(SQL.Coal.mine_id==mine_id, SQL.Coal.minable==0).all()
        if len(query) == 0:
            return 0
        else:
            return sum([coal.res_a1*coal.gas_x1 for coal in query])

    def WorkAreaGasFlow(self, work_area, K1):
        query = self.session.query(SQL.WorkSurf).filter(SQL.WorkSurf.work_area_id==work_area.id).all()
        S1 = sum([ws.qr*ws.a for ws in query])
        query = self.session.query(SQL.DrillingSurf).filter(SQL.DrillingSurf.work_area_id==work_area.id).all()
        S2 = sum([tws.qa for tws in query])
        if work_area.a <= 0:
            return -1
        else:
            return K1*(S1+S2)/work_area.a

    def MineGasFlow(self, mine):
        work_areas = self.GetWorkAreas(mine.id)
        if len(work_areas) == 0:
            return 0.0

        S1 = sum([work_area.qr*work_area.a for work_area in query])
        S2 = sum([work_area.a for work_area in query])
        if S2 <= 0:
            return -1
        else:
            K2 = mine.gas_k2
            return K2*S1/S2

    def WorkSurfGasFlow1(self, coal, work_area, work_surf):
        K1 = work_surf.k1
        K2 = work_surf.k2
        K3 = work_surf.k3
        kf = work_surf.kf
        # ���ɲ���(????�ֲ���ο���???)
        m = coal.thick
        # ������ɸ�
        M = coal.hw
        W0 = coal.gas_w0
        Wc = coal.gas_wc2

        # ���㿪�ɲ������˹ӿ����q1
        if work_surf.layerable == 0:
            return K1 * K2 * K3 * ( W0 - Wc ) * m / M
        else:
            return K1 * K2 * K3 * ( W0 - Wc ) * kf

    def WorkSurfGasFlow2(self, coal, work_area, work_surf):
        query = self.session.query(SQL.AdjLayer).filter(SQL.AdjLayer.work_surf_id==work_surf.id).all()
        if len(query) == 0:
            return 0.0
        f = lambda adj_coal:(adj_coal.gas_w0-adj_coal.gas_wc2)*adj_coal.thick*adj_coal.gas_eta
        S = sum([f(adj_layer.coal) for adj_layer in query])
        M = coal.hw
        return S / M

    def DrillingSurfGasFlow(self, coal, drilling_surf, tunnel):
        # ����q0
        Vr = coal.vr
        W0 = coal.gas_w0
        D = tunnel.d
        v = tunnel.v
        L = tunnel.l
        S = tunnel.s
        r = coal.rho
        Wc = coal.gas_wc2
        q0 = ( 0.0004 * pow( Vr, 2 ) + 0.16 ) * 0.026 * W0
        q3 = D * v * q0 * ( 2 * sqrt( L / v ) - 1 )
        q4 = S * v * r * ( W0 - Wc )
        qa = q3 + q4 #  �������˹ӿ����

        # ���������浽�����ṹ��
        ret = DrillingSurfGasFlowResult()
        ret.q0 = q0
        ret.q3 = q3
        ret.q4 = q4
        ret.qa = qa
        return ret

    def SendCommandToCAD(self, cmd):
        exe = '..\\..\\x64\\Debug\\send'
        subprocess.Popen('%s %s' % (exe, cmd))

    def RequestJsonDatasFromCAD(self, data_type):
        global POST_DATA_FROM_CAD_CACHE
        # ����36λ��Կ
        secret_key = str(uuid.uuid1())
        # ��cad�������JL.PostJsonDatas ���������id  ��Կ
        self.SendCommandToCAD("%s %d %s" % ("JL.PostJsonDatas", data_type, secret_key))
        # ���������Կֵ
        key = "%d_%s" % (data_type, secret_key)
        print "�����:������Կ:", key
        # ����ռ����ڴ������
        POST_DATA_FROM_CAD_CACHE[key] = "{}"
        return key

    def GetJsonDatasFromRpcCache(self, secret_key):
        global POST_DATA_FROM_CAD_CACHE
        print "�����:�ӻ����л�ȡ����"
        if secret_key not in POST_DATA_FROM_CAD_CACHE:
            return "{}"
        else:
            json_datas = POST_DATA_FROM_CAD_CACHE[secret_key]
            del POST_DATA_FROM_CAD_CACHE[secret_key]
            return json_datas

    def PostJsonDatasFromCAD(self, data_type, secret_key, json_datas):
        global POST_DATA_FROM_CAD_CACHE
        key = "%d_%s" % (data_type, secret_key)
        if key in POST_DATA_FROM_CAD_CACHE:
            POST_DATA_FROM_CAD_CACHE[key] = json_datas
            print '�����: ��������:%s  ��Կ:%s' % (json_datas, secret_key)
        # print '�����: ���»���:', POST_DATA_FROM_CAD_CACHE

# ����������
def create_server(host, port):
     # sqlalchemy����mysql���ݿ�
    Session = init_sqlalchemy()
    # ����rpc��Ϣ�����ӿ�
    handler = CbmServiceHandler(Session)
    processor = CbmService.Processor(handler)
    # ����thrift rpc������
    server = ThriftServerHelper.make_rpc_server(processor, host=host, port=port)
    return handler, server