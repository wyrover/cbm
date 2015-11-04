#-*- coding:utf-8 -*-

from cbm.ttypes import *
import sql
import CbmUtil


class SQLServiceHandler(object):
	def __init__(self, session):
		self.session = session

	#Account 类型的CRUD操作
	def AddAccount(self, account):
		sql_obj = sql.Account()
		CbmUtil.CopyAttribs(account, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteAccount(self, id):
		ret=True
		try:
			self.session.query(sql.Account).filter(sql.Account.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateAccount(self, account):
		ret=True
		try:
			sql_obj = sql.Account()
			CbmUtil.CopyAttribs(account, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.Account).filter(sql.Account.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetAccountById(self, id):
		query=self.session.query(sql.Account).filter(sql.Account.id==id).first()
		obj = Account()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetAccountByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.Account).filter_by(**fields).first()
		obj = Account()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetAccountList(self):
		query=self.session.query(sql.Account).all()
		n = len(query)
		obj_list = [Account() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetAccountIds(self):
		query=self.session.query(sql.Account).all()
		return [obj.id for obj in query]
	def GetAccountNames(self):
		query=self.session.query(sql.Account).all()
		if hasattr(Account, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreAccount(self, objs):
		n = len(objs)
		sql_objs = [sql.Account() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreAccount(self, obj_ids):
		self.session.query(sql.Account).filter(sql.Account.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetAccountByFields(self, fields):
		query = self.session.query(sql.Account).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [Account() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetAccountByFields(self, fields):
		objs = self.__GetAccountByFields(fields)
		if len(objs) == 0:
			obj = Account()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetAccountByFields1(self, field, value):
		return self.GetAccountByFields({field:value})
	def GetAccountByFields2(self, field1, value1, field2, value2):
		return self.GetAccountByFields({field1:value1, field2:value2})
	def GetAccountListByFields(self, fields):
		return self.__GetAccountByFields(fields)
	def GetAccountListByFields1(self, field, value):
		return self.GetAccountListByFields({field:value})
	def GetAccountListByFields2(self, field1, value1, field2, value2):
		return self.GetAccountListByFields({field1:value1, field2:value2})

	#AdjLayer 类型的CRUD操作
	def AddAdjLayer(self, adj_layer):
		sql_obj = sql.AdjLayer()
		CbmUtil.CopyAttribs(adj_layer, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteAdjLayer(self, id):
		ret=True
		try:
			self.session.query(sql.AdjLayer).filter(sql.AdjLayer.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateAdjLayer(self, adj_layer):
		ret=True
		try:
			sql_obj = sql.AdjLayer()
			CbmUtil.CopyAttribs(adj_layer, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.AdjLayer).filter(sql.AdjLayer.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetAdjLayerById(self, id):
		query=self.session.query(sql.AdjLayer).filter(sql.AdjLayer.id==id).first()
		obj = AdjLayer()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetAdjLayerByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.AdjLayer).filter_by(**fields).first()
		obj = AdjLayer()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetAdjLayerList(self):
		query=self.session.query(sql.AdjLayer).all()
		n = len(query)
		obj_list = [AdjLayer() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetAdjLayerIds(self):
		query=self.session.query(sql.AdjLayer).all()
		return [obj.id for obj in query]
	def GetAdjLayerNames(self):
		query=self.session.query(sql.AdjLayer).all()
		if hasattr(AdjLayer, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreAdjLayer(self, objs):
		n = len(objs)
		sql_objs = [sql.AdjLayer() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreAdjLayer(self, obj_ids):
		self.session.query(sql.AdjLayer).filter(sql.AdjLayer.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetAdjLayerByFields(self, fields):
		query = self.session.query(sql.AdjLayer).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [AdjLayer() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetAdjLayerByFields(self, fields):
		objs = self.__GetAdjLayerByFields(fields)
		if len(objs) == 0:
			obj = AdjLayer()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetAdjLayerByFields1(self, field, value):
		return self.GetAdjLayerByFields({field:value})
	def GetAdjLayerByFields2(self, field1, value1, field2, value2):
		return self.GetAdjLayerByFields({field1:value1, field2:value2})
	def GetAdjLayerListByFields(self, fields):
		return self.__GetAdjLayerByFields(fields)
	def GetAdjLayerListByFields1(self, field, value):
		return self.GetAdjLayerListByFields({field:value})
	def GetAdjLayerListByFields2(self, field1, value1, field2, value2):
		return self.GetAdjLayerListByFields({field1:value1, field2:value2})

	#Coal 类型的CRUD操作
	def AddCoal(self, coal):
		sql_obj = sql.Coal()
		CbmUtil.CopyAttribs(coal, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteCoal(self, id):
		ret=True
		try:
			self.session.query(sql.Coal).filter(sql.Coal.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateCoal(self, coal):
		ret=True
		try:
			sql_obj = sql.Coal()
			CbmUtil.CopyAttribs(coal, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.Coal).filter(sql.Coal.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetCoalById(self, id):
		query=self.session.query(sql.Coal).filter(sql.Coal.id==id).first()
		obj = Coal()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetCoalByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.Coal).filter_by(**fields).first()
		obj = Coal()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetCoalList(self):
		query=self.session.query(sql.Coal).all()
		n = len(query)
		obj_list = [Coal() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetCoalIds(self):
		query=self.session.query(sql.Coal).all()
		return [obj.id for obj in query]
	def GetCoalNames(self):
		query=self.session.query(sql.Coal).all()
		if hasattr(Coal, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreCoal(self, objs):
		n = len(objs)
		sql_objs = [sql.Coal() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreCoal(self, obj_ids):
		self.session.query(sql.Coal).filter(sql.Coal.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetCoalByFields(self, fields):
		query = self.session.query(sql.Coal).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [Coal() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetCoalByFields(self, fields):
		objs = self.__GetCoalByFields(fields)
		if len(objs) == 0:
			obj = Coal()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetCoalByFields1(self, field, value):
		return self.GetCoalByFields({field:value})
	def GetCoalByFields2(self, field1, value1, field2, value2):
		return self.GetCoalByFields({field1:value1, field2:value2})
	def GetCoalListByFields(self, fields):
		return self.__GetCoalByFields(fields)
	def GetCoalListByFields1(self, field, value):
		return self.GetCoalListByFields({field:value})
	def GetCoalListByFields2(self, field1, value1, field2, value2):
		return self.GetCoalListByFields({field1:value1, field2:value2})

	#Complexity 类型的CRUD操作
	def AddComplexity(self, complexity):
		sql_obj = sql.Complexity()
		CbmUtil.CopyAttribs(complexity, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteComplexity(self, id):
		ret=True
		try:
			self.session.query(sql.Complexity).filter(sql.Complexity.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateComplexity(self, complexity):
		ret=True
		try:
			sql_obj = sql.Complexity()
			CbmUtil.CopyAttribs(complexity, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.Complexity).filter(sql.Complexity.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetComplexityById(self, id):
		query=self.session.query(sql.Complexity).filter(sql.Complexity.id==id).first()
		obj = Complexity()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetComplexityByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.Complexity).filter_by(**fields).first()
		obj = Complexity()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetComplexityList(self):
		query=self.session.query(sql.Complexity).all()
		n = len(query)
		obj_list = [Complexity() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetComplexityIds(self):
		query=self.session.query(sql.Complexity).all()
		return [obj.id for obj in query]
	def GetComplexityNames(self):
		query=self.session.query(sql.Complexity).all()
		if hasattr(Complexity, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreComplexity(self, objs):
		n = len(objs)
		sql_objs = [sql.Complexity() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreComplexity(self, obj_ids):
		self.session.query(sql.Complexity).filter(sql.Complexity.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetComplexityByFields(self, fields):
		query = self.session.query(sql.Complexity).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [Complexity() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetComplexityByFields(self, fields):
		objs = self.__GetComplexityByFields(fields)
		if len(objs) == 0:
			obj = Complexity()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetComplexityByFields1(self, field, value):
		return self.GetComplexityByFields({field:value})
	def GetComplexityByFields2(self, field1, value1, field2, value2):
		return self.GetComplexityByFields({field1:value1, field2:value2})
	def GetComplexityListByFields(self, fields):
		return self.__GetComplexityByFields(fields)
	def GetComplexityListByFields1(self, field, value):
		return self.GetComplexityListByFields({field:value})
	def GetComplexityListByFields2(self, field1, value1, field2, value2):
		return self.GetComplexityListByFields({field1:value1, field2:value2})

	#DesignDrillingSurfTechnology 类型的CRUD操作
	def AddDesignDrillingSurfTechnology(self, design_drilling_surf_technology):
		sql_obj = sql.DesignDrillingSurfTechnology()
		CbmUtil.CopyAttribs(design_drilling_surf_technology, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteDesignDrillingSurfTechnology(self, id):
		ret=True
		try:
			self.session.query(sql.DesignDrillingSurfTechnology).filter(sql.DesignDrillingSurfTechnology.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateDesignDrillingSurfTechnology(self, design_drilling_surf_technology):
		ret=True
		try:
			sql_obj = sql.DesignDrillingSurfTechnology()
			CbmUtil.CopyAttribs(design_drilling_surf_technology, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.DesignDrillingSurfTechnology).filter(sql.DesignDrillingSurfTechnology.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetDesignDrillingSurfTechnologyById(self, id):
		query=self.session.query(sql.DesignDrillingSurfTechnology).filter(sql.DesignDrillingSurfTechnology.id==id).first()
		obj = DesignDrillingSurfTechnology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignDrillingSurfTechnologyByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.DesignDrillingSurfTechnology).filter_by(**fields).first()
		obj = DesignDrillingSurfTechnology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignDrillingSurfTechnologyList(self):
		query=self.session.query(sql.DesignDrillingSurfTechnology).all()
		n = len(query)
		obj_list = [DesignDrillingSurfTechnology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetDesignDrillingSurfTechnologyIds(self):
		query=self.session.query(sql.DesignDrillingSurfTechnology).all()
		return [obj.id for obj in query]
	def GetDesignDrillingSurfTechnologyNames(self):
		query=self.session.query(sql.DesignDrillingSurfTechnology).all()
		if hasattr(DesignDrillingSurfTechnology, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreDesignDrillingSurfTechnology(self, objs):
		n = len(objs)
		sql_objs = [sql.DesignDrillingSurfTechnology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreDesignDrillingSurfTechnology(self, obj_ids):
		self.session.query(sql.DesignDrillingSurfTechnology).filter(sql.DesignDrillingSurfTechnology.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetDesignDrillingSurfTechnologyByFields(self, fields):
		query = self.session.query(sql.DesignDrillingSurfTechnology).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [DesignDrillingSurfTechnology() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetDesignDrillingSurfTechnologyByFields(self, fields):
		objs = self.__GetDesignDrillingSurfTechnologyByFields(fields)
		if len(objs) == 0:
			obj = DesignDrillingSurfTechnology()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetDesignDrillingSurfTechnologyByFields1(self, field, value):
		return self.GetDesignDrillingSurfTechnologyByFields({field:value})
	def GetDesignDrillingSurfTechnologyByFields2(self, field1, value1, field2, value2):
		return self.GetDesignDrillingSurfTechnologyByFields({field1:value1, field2:value2})
	def GetDesignDrillingSurfTechnologyListByFields(self, fields):
		return self.__GetDesignDrillingSurfTechnologyByFields(fields)
	def GetDesignDrillingSurfTechnologyListByFields1(self, field, value):
		return self.GetDesignDrillingSurfTechnologyListByFields({field:value})
	def GetDesignDrillingSurfTechnologyListByFields2(self, field1, value1, field2, value2):
		return self.GetDesignDrillingSurfTechnologyListByFields({field1:value1, field2:value2})

	#DesignGoafTechnology 类型的CRUD操作
	def AddDesignGoafTechnology(self, design_goaf_technology):
		sql_obj = sql.DesignGoafTechnology()
		CbmUtil.CopyAttribs(design_goaf_technology, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteDesignGoafTechnology(self, id):
		ret=True
		try:
			self.session.query(sql.DesignGoafTechnology).filter(sql.DesignGoafTechnology.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateDesignGoafTechnology(self, design_goaf_technology):
		ret=True
		try:
			sql_obj = sql.DesignGoafTechnology()
			CbmUtil.CopyAttribs(design_goaf_technology, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.DesignGoafTechnology).filter(sql.DesignGoafTechnology.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetDesignGoafTechnologyById(self, id):
		query=self.session.query(sql.DesignGoafTechnology).filter(sql.DesignGoafTechnology.id==id).first()
		obj = DesignGoafTechnology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignGoafTechnologyByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.DesignGoafTechnology).filter_by(**fields).first()
		obj = DesignGoafTechnology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignGoafTechnologyList(self):
		query=self.session.query(sql.DesignGoafTechnology).all()
		n = len(query)
		obj_list = [DesignGoafTechnology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetDesignGoafTechnologyIds(self):
		query=self.session.query(sql.DesignGoafTechnology).all()
		return [obj.id for obj in query]
	def GetDesignGoafTechnologyNames(self):
		query=self.session.query(sql.DesignGoafTechnology).all()
		if hasattr(DesignGoafTechnology, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreDesignGoafTechnology(self, objs):
		n = len(objs)
		sql_objs = [sql.DesignGoafTechnology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreDesignGoafTechnology(self, obj_ids):
		self.session.query(sql.DesignGoafTechnology).filter(sql.DesignGoafTechnology.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetDesignGoafTechnologyByFields(self, fields):
		query = self.session.query(sql.DesignGoafTechnology).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [DesignGoafTechnology() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetDesignGoafTechnologyByFields(self, fields):
		objs = self.__GetDesignGoafTechnologyByFields(fields)
		if len(objs) == 0:
			obj = DesignGoafTechnology()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetDesignGoafTechnologyByFields1(self, field, value):
		return self.GetDesignGoafTechnologyByFields({field:value})
	def GetDesignGoafTechnologyByFields2(self, field1, value1, field2, value2):
		return self.GetDesignGoafTechnologyByFields({field1:value1, field2:value2})
	def GetDesignGoafTechnologyListByFields(self, fields):
		return self.__GetDesignGoafTechnologyByFields(fields)
	def GetDesignGoafTechnologyListByFields1(self, field, value):
		return self.GetDesignGoafTechnologyListByFields({field:value})
	def GetDesignGoafTechnologyListByFields2(self, field1, value1, field2, value2):
		return self.GetDesignGoafTechnologyListByFields({field1:value1, field2:value2})

	#DesignPore 类型的CRUD操作
	def AddDesignPore(self, design_pore):
		sql_obj = sql.DesignPore()
		CbmUtil.CopyAttribs(design_pore, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteDesignPore(self, id):
		ret=True
		try:
			self.session.query(sql.DesignPore).filter(sql.DesignPore.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateDesignPore(self, design_pore):
		ret=True
		try:
			sql_obj = sql.DesignPore()
			CbmUtil.CopyAttribs(design_pore, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.DesignPore).filter(sql.DesignPore.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetDesignPoreById(self, id):
		query=self.session.query(sql.DesignPore).filter(sql.DesignPore.id==id).first()
		obj = DesignPore()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignPoreByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.DesignPore).filter_by(**fields).first()
		obj = DesignPore()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignPoreList(self):
		query=self.session.query(sql.DesignPore).all()
		n = len(query)
		obj_list = [DesignPore() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetDesignPoreIds(self):
		query=self.session.query(sql.DesignPore).all()
		return [obj.id for obj in query]
	def GetDesignPoreNames(self):
		query=self.session.query(sql.DesignPore).all()
		if hasattr(DesignPore, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreDesignPore(self, objs):
		n = len(objs)
		sql_objs = [sql.DesignPore() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreDesignPore(self, obj_ids):
		self.session.query(sql.DesignPore).filter(sql.DesignPore.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetDesignPoreByFields(self, fields):
		query = self.session.query(sql.DesignPore).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [DesignPore() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetDesignPoreByFields(self, fields):
		objs = self.__GetDesignPoreByFields(fields)
		if len(objs) == 0:
			obj = DesignPore()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetDesignPoreByFields1(self, field, value):
		return self.GetDesignPoreByFields({field:value})
	def GetDesignPoreByFields2(self, field1, value1, field2, value2):
		return self.GetDesignPoreByFields({field1:value1, field2:value2})
	def GetDesignPoreListByFields(self, fields):
		return self.__GetDesignPoreByFields(fields)
	def GetDesignPoreListByFields1(self, field, value):
		return self.GetDesignPoreListByFields({field:value})
	def GetDesignPoreListByFields2(self, field1, value1, field2, value2):
		return self.GetDesignPoreListByFields({field1:value1, field2:value2})

	#DesignSite 类型的CRUD操作
	def AddDesignSite(self, design_site):
		sql_obj = sql.DesignSite()
		CbmUtil.CopyAttribs(design_site, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteDesignSite(self, id):
		ret=True
		try:
			self.session.query(sql.DesignSite).filter(sql.DesignSite.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateDesignSite(self, design_site):
		ret=True
		try:
			sql_obj = sql.DesignSite()
			CbmUtil.CopyAttribs(design_site, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.DesignSite).filter(sql.DesignSite.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetDesignSiteById(self, id):
		query=self.session.query(sql.DesignSite).filter(sql.DesignSite.id==id).first()
		obj = DesignSite()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignSiteByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.DesignSite).filter_by(**fields).first()
		obj = DesignSite()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignSiteList(self):
		query=self.session.query(sql.DesignSite).all()
		n = len(query)
		obj_list = [DesignSite() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetDesignSiteIds(self):
		query=self.session.query(sql.DesignSite).all()
		return [obj.id for obj in query]
	def GetDesignSiteNames(self):
		query=self.session.query(sql.DesignSite).all()
		if hasattr(DesignSite, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreDesignSite(self, objs):
		n = len(objs)
		sql_objs = [sql.DesignSite() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreDesignSite(self, obj_ids):
		self.session.query(sql.DesignSite).filter(sql.DesignSite.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetDesignSiteByFields(self, fields):
		query = self.session.query(sql.DesignSite).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [DesignSite() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetDesignSiteByFields(self, fields):
		objs = self.__GetDesignSiteByFields(fields)
		if len(objs) == 0:
			obj = DesignSite()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetDesignSiteByFields1(self, field, value):
		return self.GetDesignSiteByFields({field:value})
	def GetDesignSiteByFields2(self, field1, value1, field2, value2):
		return self.GetDesignSiteByFields({field1:value1, field2:value2})
	def GetDesignSiteListByFields(self, fields):
		return self.__GetDesignSiteByFields(fields)
	def GetDesignSiteListByFields1(self, field, value):
		return self.GetDesignSiteListByFields({field:value})
	def GetDesignSiteListByFields2(self, field1, value1, field2, value2):
		return self.GetDesignSiteListByFields({field1:value1, field2:value2})

	#DesignTechnology 类型的CRUD操作
	def AddDesignTechnology(self, design_technology):
		sql_obj = sql.DesignTechnology()
		CbmUtil.CopyAttribs(design_technology, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteDesignTechnology(self, id):
		ret=True
		try:
			self.session.query(sql.DesignTechnology).filter(sql.DesignTechnology.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateDesignTechnology(self, design_technology):
		ret=True
		try:
			sql_obj = sql.DesignTechnology()
			CbmUtil.CopyAttribs(design_technology, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.DesignTechnology).filter(sql.DesignTechnology.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetDesignTechnologyById(self, id):
		query=self.session.query(sql.DesignTechnology).filter(sql.DesignTechnology.id==id).first()
		obj = DesignTechnology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignTechnologyByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.DesignTechnology).filter_by(**fields).first()
		obj = DesignTechnology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignTechnologyList(self):
		query=self.session.query(sql.DesignTechnology).all()
		n = len(query)
		obj_list = [DesignTechnology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetDesignTechnologyIds(self):
		query=self.session.query(sql.DesignTechnology).all()
		return [obj.id for obj in query]
	def GetDesignTechnologyNames(self):
		query=self.session.query(sql.DesignTechnology).all()
		if hasattr(DesignTechnology, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreDesignTechnology(self, objs):
		n = len(objs)
		sql_objs = [sql.DesignTechnology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreDesignTechnology(self, obj_ids):
		self.session.query(sql.DesignTechnology).filter(sql.DesignTechnology.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetDesignTechnologyByFields(self, fields):
		query = self.session.query(sql.DesignTechnology).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [DesignTechnology() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetDesignTechnologyByFields(self, fields):
		objs = self.__GetDesignTechnologyByFields(fields)
		if len(objs) == 0:
			obj = DesignTechnology()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetDesignTechnologyByFields1(self, field, value):
		return self.GetDesignTechnologyByFields({field:value})
	def GetDesignTechnologyByFields2(self, field1, value1, field2, value2):
		return self.GetDesignTechnologyByFields({field1:value1, field2:value2})
	def GetDesignTechnologyListByFields(self, fields):
		return self.__GetDesignTechnologyByFields(fields)
	def GetDesignTechnologyListByFields1(self, field, value):
		return self.GetDesignTechnologyListByFields({field:value})
	def GetDesignTechnologyListByFields2(self, field1, value1, field2, value2):
		return self.GetDesignTechnologyListByFields({field1:value1, field2:value2})

	#DesignWorkSurfTechnology 类型的CRUD操作
	def AddDesignWorkSurfTechnology(self, design_work_surf_technology):
		sql_obj = sql.DesignWorkSurfTechnology()
		CbmUtil.CopyAttribs(design_work_surf_technology, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteDesignWorkSurfTechnology(self, id):
		ret=True
		try:
			self.session.query(sql.DesignWorkSurfTechnology).filter(sql.DesignWorkSurfTechnology.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateDesignWorkSurfTechnology(self, design_work_surf_technology):
		ret=True
		try:
			sql_obj = sql.DesignWorkSurfTechnology()
			CbmUtil.CopyAttribs(design_work_surf_technology, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.DesignWorkSurfTechnology).filter(sql.DesignWorkSurfTechnology.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetDesignWorkSurfTechnologyById(self, id):
		query=self.session.query(sql.DesignWorkSurfTechnology).filter(sql.DesignWorkSurfTechnology.id==id).first()
		obj = DesignWorkSurfTechnology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignWorkSurfTechnologyByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.DesignWorkSurfTechnology).filter_by(**fields).first()
		obj = DesignWorkSurfTechnology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDesignWorkSurfTechnologyList(self):
		query=self.session.query(sql.DesignWorkSurfTechnology).all()
		n = len(query)
		obj_list = [DesignWorkSurfTechnology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetDesignWorkSurfTechnologyIds(self):
		query=self.session.query(sql.DesignWorkSurfTechnology).all()
		return [obj.id for obj in query]
	def GetDesignWorkSurfTechnologyNames(self):
		query=self.session.query(sql.DesignWorkSurfTechnology).all()
		if hasattr(DesignWorkSurfTechnology, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreDesignWorkSurfTechnology(self, objs):
		n = len(objs)
		sql_objs = [sql.DesignWorkSurfTechnology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreDesignWorkSurfTechnology(self, obj_ids):
		self.session.query(sql.DesignWorkSurfTechnology).filter(sql.DesignWorkSurfTechnology.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetDesignWorkSurfTechnologyByFields(self, fields):
		query = self.session.query(sql.DesignWorkSurfTechnology).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [DesignWorkSurfTechnology() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetDesignWorkSurfTechnologyByFields(self, fields):
		objs = self.__GetDesignWorkSurfTechnologyByFields(fields)
		if len(objs) == 0:
			obj = DesignWorkSurfTechnology()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetDesignWorkSurfTechnologyByFields1(self, field, value):
		return self.GetDesignWorkSurfTechnologyByFields({field:value})
	def GetDesignWorkSurfTechnologyByFields2(self, field1, value1, field2, value2):
		return self.GetDesignWorkSurfTechnologyByFields({field1:value1, field2:value2})
	def GetDesignWorkSurfTechnologyListByFields(self, fields):
		return self.__GetDesignWorkSurfTechnologyByFields(fields)
	def GetDesignWorkSurfTechnologyListByFields1(self, field, value):
		return self.GetDesignWorkSurfTechnologyListByFields({field:value})
	def GetDesignWorkSurfTechnologyListByFields2(self, field1, value1, field2, value2):
		return self.GetDesignWorkSurfTechnologyListByFields({field1:value1, field2:value2})

	#DrillingRadiusParam 类型的CRUD操作
	def AddDrillingRadiusParam(self, drilling_radius_param):
		sql_obj = sql.DrillingRadiusParam()
		CbmUtil.CopyAttribs(drilling_radius_param, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteDrillingRadiusParam(self, id):
		ret=True
		try:
			self.session.query(sql.DrillingRadiusParam).filter(sql.DrillingRadiusParam.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateDrillingRadiusParam(self, drilling_radius_param):
		ret=True
		try:
			sql_obj = sql.DrillingRadiusParam()
			CbmUtil.CopyAttribs(drilling_radius_param, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.DrillingRadiusParam).filter(sql.DrillingRadiusParam.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetDrillingRadiusParamById(self, id):
		query=self.session.query(sql.DrillingRadiusParam).filter(sql.DrillingRadiusParam.id==id).first()
		obj = DrillingRadiusParam()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDrillingRadiusParamByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.DrillingRadiusParam).filter_by(**fields).first()
		obj = DrillingRadiusParam()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDrillingRadiusParamList(self):
		query=self.session.query(sql.DrillingRadiusParam).all()
		n = len(query)
		obj_list = [DrillingRadiusParam() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetDrillingRadiusParamIds(self):
		query=self.session.query(sql.DrillingRadiusParam).all()
		return [obj.id for obj in query]
	def GetDrillingRadiusParamNames(self):
		query=self.session.query(sql.DrillingRadiusParam).all()
		if hasattr(DrillingRadiusParam, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreDrillingRadiusParam(self, objs):
		n = len(objs)
		sql_objs = [sql.DrillingRadiusParam() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreDrillingRadiusParam(self, obj_ids):
		self.session.query(sql.DrillingRadiusParam).filter(sql.DrillingRadiusParam.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetDrillingRadiusParamByFields(self, fields):
		query = self.session.query(sql.DrillingRadiusParam).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [DrillingRadiusParam() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetDrillingRadiusParamByFields(self, fields):
		objs = self.__GetDrillingRadiusParamByFields(fields)
		if len(objs) == 0:
			obj = DrillingRadiusParam()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetDrillingRadiusParamByFields1(self, field, value):
		return self.GetDrillingRadiusParamByFields({field:value})
	def GetDrillingRadiusParamByFields2(self, field1, value1, field2, value2):
		return self.GetDrillingRadiusParamByFields({field1:value1, field2:value2})
	def GetDrillingRadiusParamListByFields(self, fields):
		return self.__GetDrillingRadiusParamByFields(fields)
	def GetDrillingRadiusParamListByFields1(self, field, value):
		return self.GetDrillingRadiusParamListByFields({field:value})
	def GetDrillingRadiusParamListByFields2(self, field1, value1, field2, value2):
		return self.GetDrillingRadiusParamListByFields({field1:value1, field2:value2})

	#DrillingSurf 类型的CRUD操作
	def AddDrillingSurf(self, drilling_surf):
		sql_obj = sql.DrillingSurf()
		CbmUtil.CopyAttribs(drilling_surf, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteDrillingSurf(self, id):
		ret=True
		try:
			self.session.query(sql.DrillingSurf).filter(sql.DrillingSurf.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateDrillingSurf(self, drilling_surf):
		ret=True
		try:
			sql_obj = sql.DrillingSurf()
			CbmUtil.CopyAttribs(drilling_surf, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.DrillingSurf).filter(sql.DrillingSurf.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetDrillingSurfById(self, id):
		query=self.session.query(sql.DrillingSurf).filter(sql.DrillingSurf.id==id).first()
		obj = DrillingSurf()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDrillingSurfByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.DrillingSurf).filter_by(**fields).first()
		obj = DrillingSurf()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetDrillingSurfList(self):
		query=self.session.query(sql.DrillingSurf).all()
		n = len(query)
		obj_list = [DrillingSurf() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetDrillingSurfIds(self):
		query=self.session.query(sql.DrillingSurf).all()
		return [obj.id for obj in query]
	def GetDrillingSurfNames(self):
		query=self.session.query(sql.DrillingSurf).all()
		if hasattr(DrillingSurf, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreDrillingSurf(self, objs):
		n = len(objs)
		sql_objs = [sql.DrillingSurf() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreDrillingSurf(self, obj_ids):
		self.session.query(sql.DrillingSurf).filter(sql.DrillingSurf.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetDrillingSurfByFields(self, fields):
		query = self.session.query(sql.DrillingSurf).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [DrillingSurf() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetDrillingSurfByFields(self, fields):
		objs = self.__GetDrillingSurfByFields(fields)
		if len(objs) == 0:
			obj = DrillingSurf()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetDrillingSurfByFields1(self, field, value):
		return self.GetDrillingSurfByFields({field:value})
	def GetDrillingSurfByFields2(self, field1, value1, field2, value2):
		return self.GetDrillingSurfByFields({field1:value1, field2:value2})
	def GetDrillingSurfListByFields(self, fields):
		return self.__GetDrillingSurfByFields(fields)
	def GetDrillingSurfListByFields1(self, field, value):
		return self.GetDrillingSurfListByFields({field:value})
	def GetDrillingSurfListByFields2(self, field1, value1, field2, value2):
		return self.GetDrillingSurfListByFields({field1:value1, field2:value2})

	#EvalUnit 类型的CRUD操作
	def AddEvalUnit(self, eval_unit):
		sql_obj = sql.EvalUnit()
		CbmUtil.CopyAttribs(eval_unit, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteEvalUnit(self, id):
		ret=True
		try:
			self.session.query(sql.EvalUnit).filter(sql.EvalUnit.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateEvalUnit(self, eval_unit):
		ret=True
		try:
			sql_obj = sql.EvalUnit()
			CbmUtil.CopyAttribs(eval_unit, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.EvalUnit).filter(sql.EvalUnit.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetEvalUnitById(self, id):
		query=self.session.query(sql.EvalUnit).filter(sql.EvalUnit.id==id).first()
		obj = EvalUnit()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetEvalUnitByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.EvalUnit).filter_by(**fields).first()
		obj = EvalUnit()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetEvalUnitList(self):
		query=self.session.query(sql.EvalUnit).all()
		n = len(query)
		obj_list = [EvalUnit() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetEvalUnitIds(self):
		query=self.session.query(sql.EvalUnit).all()
		return [obj.id for obj in query]
	def GetEvalUnitNames(self):
		query=self.session.query(sql.EvalUnit).all()
		if hasattr(EvalUnit, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreEvalUnit(self, objs):
		n = len(objs)
		sql_objs = [sql.EvalUnit() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreEvalUnit(self, obj_ids):
		self.session.query(sql.EvalUnit).filter(sql.EvalUnit.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetEvalUnitByFields(self, fields):
		query = self.session.query(sql.EvalUnit).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [EvalUnit() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetEvalUnitByFields(self, fields):
		objs = self.__GetEvalUnitByFields(fields)
		if len(objs) == 0:
			obj = EvalUnit()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetEvalUnitByFields1(self, field, value):
		return self.GetEvalUnitByFields({field:value})
	def GetEvalUnitByFields2(self, field1, value1, field2, value2):
		return self.GetEvalUnitByFields({field1:value1, field2:value2})
	def GetEvalUnitListByFields(self, fields):
		return self.__GetEvalUnitByFields(fields)
	def GetEvalUnitListByFields1(self, field, value):
		return self.GetEvalUnitListByFields({field:value})
	def GetEvalUnitListByFields2(self, field1, value1, field2, value2):
		return self.GetEvalUnitListByFields({field1:value1, field2:value2})

	#HighDrillingPore 类型的CRUD操作
	def AddHighDrillingPore(self, high_drilling_pore):
		sql_obj = sql.HighDrillingPore()
		CbmUtil.CopyAttribs(high_drilling_pore, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteHighDrillingPore(self, id):
		ret=True
		try:
			self.session.query(sql.HighDrillingPore).filter(sql.HighDrillingPore.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateHighDrillingPore(self, high_drilling_pore):
		ret=True
		try:
			sql_obj = sql.HighDrillingPore()
			CbmUtil.CopyAttribs(high_drilling_pore, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.HighDrillingPore).filter(sql.HighDrillingPore.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetHighDrillingPoreById(self, id):
		query=self.session.query(sql.HighDrillingPore).filter(sql.HighDrillingPore.id==id).first()
		obj = HighDrillingPore()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHighDrillingPoreByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.HighDrillingPore).filter_by(**fields).first()
		obj = HighDrillingPore()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHighDrillingPoreList(self):
		query=self.session.query(sql.HighDrillingPore).all()
		n = len(query)
		obj_list = [HighDrillingPore() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetHighDrillingPoreIds(self):
		query=self.session.query(sql.HighDrillingPore).all()
		return [obj.id for obj in query]
	def GetHighDrillingPoreNames(self):
		query=self.session.query(sql.HighDrillingPore).all()
		if hasattr(HighDrillingPore, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreHighDrillingPore(self, objs):
		n = len(objs)
		sql_objs = [sql.HighDrillingPore() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreHighDrillingPore(self, obj_ids):
		self.session.query(sql.HighDrillingPore).filter(sql.HighDrillingPore.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetHighDrillingPoreByFields(self, fields):
		query = self.session.query(sql.HighDrillingPore).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [HighDrillingPore() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetHighDrillingPoreByFields(self, fields):
		objs = self.__GetHighDrillingPoreByFields(fields)
		if len(objs) == 0:
			obj = HighDrillingPore()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetHighDrillingPoreByFields1(self, field, value):
		return self.GetHighDrillingPoreByFields({field:value})
	def GetHighDrillingPoreByFields2(self, field1, value1, field2, value2):
		return self.GetHighDrillingPoreByFields({field1:value1, field2:value2})
	def GetHighDrillingPoreListByFields(self, fields):
		return self.__GetHighDrillingPoreByFields(fields)
	def GetHighDrillingPoreListByFields1(self, field, value):
		return self.GetHighDrillingPoreListByFields({field:value})
	def GetHighDrillingPoreListByFields2(self, field1, value1, field2, value2):
		return self.GetHighDrillingPoreListByFields({field1:value1, field2:value2})

	#HighDrillingPoreParam 类型的CRUD操作
	def AddHighDrillingPoreParam(self, high_drilling_pore_param):
		sql_obj = sql.HighDrillingPoreParam()
		CbmUtil.CopyAttribs(high_drilling_pore_param, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteHighDrillingPoreParam(self, id):
		ret=True
		try:
			self.session.query(sql.HighDrillingPoreParam).filter(sql.HighDrillingPoreParam.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateHighDrillingPoreParam(self, high_drilling_pore_param):
		ret=True
		try:
			sql_obj = sql.HighDrillingPoreParam()
			CbmUtil.CopyAttribs(high_drilling_pore_param, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.HighDrillingPoreParam).filter(sql.HighDrillingPoreParam.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetHighDrillingPoreParamById(self, id):
		query=self.session.query(sql.HighDrillingPoreParam).filter(sql.HighDrillingPoreParam.id==id).first()
		obj = HighDrillingPoreParam()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHighDrillingPoreParamByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.HighDrillingPoreParam).filter_by(**fields).first()
		obj = HighDrillingPoreParam()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHighDrillingPoreParamList(self):
		query=self.session.query(sql.HighDrillingPoreParam).all()
		n = len(query)
		obj_list = [HighDrillingPoreParam() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetHighDrillingPoreParamIds(self):
		query=self.session.query(sql.HighDrillingPoreParam).all()
		return [obj.id for obj in query]
	def GetHighDrillingPoreParamNames(self):
		query=self.session.query(sql.HighDrillingPoreParam).all()
		if hasattr(HighDrillingPoreParam, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreHighDrillingPoreParam(self, objs):
		n = len(objs)
		sql_objs = [sql.HighDrillingPoreParam() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreHighDrillingPoreParam(self, obj_ids):
		self.session.query(sql.HighDrillingPoreParam).filter(sql.HighDrillingPoreParam.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetHighDrillingPoreParamByFields(self, fields):
		query = self.session.query(sql.HighDrillingPoreParam).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [HighDrillingPoreParam() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetHighDrillingPoreParamByFields(self, fields):
		objs = self.__GetHighDrillingPoreParamByFields(fields)
		if len(objs) == 0:
			obj = HighDrillingPoreParam()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetHighDrillingPoreParamByFields1(self, field, value):
		return self.GetHighDrillingPoreParamByFields({field:value})
	def GetHighDrillingPoreParamByFields2(self, field1, value1, field2, value2):
		return self.GetHighDrillingPoreParamByFields({field1:value1, field2:value2})
	def GetHighDrillingPoreParamListByFields(self, fields):
		return self.__GetHighDrillingPoreParamByFields(fields)
	def GetHighDrillingPoreParamListByFields1(self, field, value):
		return self.GetHighDrillingPoreParamListByFields({field:value})
	def GetHighDrillingPoreParamListByFields2(self, field1, value1, field2, value2):
		return self.GetHighDrillingPoreParamListByFields({field1:value1, field2:value2})

	#HighDrillingSiteParam 类型的CRUD操作
	def AddHighDrillingSiteParam(self, high_drilling_site_param):
		sql_obj = sql.HighDrillingSiteParam()
		CbmUtil.CopyAttribs(high_drilling_site_param, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteHighDrillingSiteParam(self, id):
		ret=True
		try:
			self.session.query(sql.HighDrillingSiteParam).filter(sql.HighDrillingSiteParam.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateHighDrillingSiteParam(self, high_drilling_site_param):
		ret=True
		try:
			sql_obj = sql.HighDrillingSiteParam()
			CbmUtil.CopyAttribs(high_drilling_site_param, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.HighDrillingSiteParam).filter(sql.HighDrillingSiteParam.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetHighDrillingSiteParamById(self, id):
		query=self.session.query(sql.HighDrillingSiteParam).filter(sql.HighDrillingSiteParam.id==id).first()
		obj = HighDrillingSiteParam()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHighDrillingSiteParamByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.HighDrillingSiteParam).filter_by(**fields).first()
		obj = HighDrillingSiteParam()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHighDrillingSiteParamList(self):
		query=self.session.query(sql.HighDrillingSiteParam).all()
		n = len(query)
		obj_list = [HighDrillingSiteParam() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetHighDrillingSiteParamIds(self):
		query=self.session.query(sql.HighDrillingSiteParam).all()
		return [obj.id for obj in query]
	def GetHighDrillingSiteParamNames(self):
		query=self.session.query(sql.HighDrillingSiteParam).all()
		if hasattr(HighDrillingSiteParam, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreHighDrillingSiteParam(self, objs):
		n = len(objs)
		sql_objs = [sql.HighDrillingSiteParam() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreHighDrillingSiteParam(self, obj_ids):
		self.session.query(sql.HighDrillingSiteParam).filter(sql.HighDrillingSiteParam.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetHighDrillingSiteParamByFields(self, fields):
		query = self.session.query(sql.HighDrillingSiteParam).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [HighDrillingSiteParam() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetHighDrillingSiteParamByFields(self, fields):
		objs = self.__GetHighDrillingSiteParamByFields(fields)
		if len(objs) == 0:
			obj = HighDrillingSiteParam()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetHighDrillingSiteParamByFields1(self, field, value):
		return self.GetHighDrillingSiteParamByFields({field:value})
	def GetHighDrillingSiteParamByFields2(self, field1, value1, field2, value2):
		return self.GetHighDrillingSiteParamByFields({field1:value1, field2:value2})
	def GetHighDrillingSiteParamListByFields(self, fields):
		return self.__GetHighDrillingSiteParamByFields(fields)
	def GetHighDrillingSiteParamListByFields1(self, field, value):
		return self.GetHighDrillingSiteParamListByFields({field:value})
	def GetHighDrillingSiteParamListByFields2(self, field1, value1, field2, value2):
		return self.GetHighDrillingSiteParamListByFields({field1:value1, field2:value2})

	#HighDrillingTunnel 类型的CRUD操作
	def AddHighDrillingTunnel(self, high_drilling_tunnel):
		sql_obj = sql.HighDrillingTunnel()
		CbmUtil.CopyAttribs(high_drilling_tunnel, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteHighDrillingTunnel(self, id):
		ret=True
		try:
			self.session.query(sql.HighDrillingTunnel).filter(sql.HighDrillingTunnel.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateHighDrillingTunnel(self, high_drilling_tunnel):
		ret=True
		try:
			sql_obj = sql.HighDrillingTunnel()
			CbmUtil.CopyAttribs(high_drilling_tunnel, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.HighDrillingTunnel).filter(sql.HighDrillingTunnel.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetHighDrillingTunnelById(self, id):
		query=self.session.query(sql.HighDrillingTunnel).filter(sql.HighDrillingTunnel.id==id).first()
		obj = HighDrillingTunnel()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHighDrillingTunnelByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.HighDrillingTunnel).filter_by(**fields).first()
		obj = HighDrillingTunnel()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHighDrillingTunnelList(self):
		query=self.session.query(sql.HighDrillingTunnel).all()
		n = len(query)
		obj_list = [HighDrillingTunnel() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetHighDrillingTunnelIds(self):
		query=self.session.query(sql.HighDrillingTunnel).all()
		return [obj.id for obj in query]
	def GetHighDrillingTunnelNames(self):
		query=self.session.query(sql.HighDrillingTunnel).all()
		if hasattr(HighDrillingTunnel, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreHighDrillingTunnel(self, objs):
		n = len(objs)
		sql_objs = [sql.HighDrillingTunnel() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreHighDrillingTunnel(self, obj_ids):
		self.session.query(sql.HighDrillingTunnel).filter(sql.HighDrillingTunnel.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetHighDrillingTunnelByFields(self, fields):
		query = self.session.query(sql.HighDrillingTunnel).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [HighDrillingTunnel() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetHighDrillingTunnelByFields(self, fields):
		objs = self.__GetHighDrillingTunnelByFields(fields)
		if len(objs) == 0:
			obj = HighDrillingTunnel()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetHighDrillingTunnelByFields1(self, field, value):
		return self.GetHighDrillingTunnelByFields({field:value})
	def GetHighDrillingTunnelByFields2(self, field1, value1, field2, value2):
		return self.GetHighDrillingTunnelByFields({field1:value1, field2:value2})
	def GetHighDrillingTunnelListByFields(self, fields):
		return self.__GetHighDrillingTunnelByFields(fields)
	def GetHighDrillingTunnelListByFields1(self, field, value):
		return self.GetHighDrillingTunnelListByFields({field:value})
	def GetHighDrillingTunnelListByFields2(self, field1, value1, field2, value2):
		return self.GetHighDrillingTunnelListByFields({field1:value1, field2:value2})

	#HydrGeo 类型的CRUD操作
	def AddHydrGeo(self, hydr_geo):
		sql_obj = sql.HydrGeo()
		CbmUtil.CopyAttribs(hydr_geo, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteHydrGeo(self, id):
		ret=True
		try:
			self.session.query(sql.HydrGeo).filter(sql.HydrGeo.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateHydrGeo(self, hydr_geo):
		ret=True
		try:
			sql_obj = sql.HydrGeo()
			CbmUtil.CopyAttribs(hydr_geo, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.HydrGeo).filter(sql.HydrGeo.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetHydrGeoById(self, id):
		query=self.session.query(sql.HydrGeo).filter(sql.HydrGeo.id==id).first()
		obj = HydrGeo()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHydrGeoByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.HydrGeo).filter_by(**fields).first()
		obj = HydrGeo()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetHydrGeoList(self):
		query=self.session.query(sql.HydrGeo).all()
		n = len(query)
		obj_list = [HydrGeo() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetHydrGeoIds(self):
		query=self.session.query(sql.HydrGeo).all()
		return [obj.id for obj in query]
	def GetHydrGeoNames(self):
		query=self.session.query(sql.HydrGeo).all()
		if hasattr(HydrGeo, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreHydrGeo(self, objs):
		n = len(objs)
		sql_objs = [sql.HydrGeo() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreHydrGeo(self, obj_ids):
		self.session.query(sql.HydrGeo).filter(sql.HydrGeo.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetHydrGeoByFields(self, fields):
		query = self.session.query(sql.HydrGeo).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [HydrGeo() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetHydrGeoByFields(self, fields):
		objs = self.__GetHydrGeoByFields(fields)
		if len(objs) == 0:
			obj = HydrGeo()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetHydrGeoByFields1(self, field, value):
		return self.GetHydrGeoByFields({field:value})
	def GetHydrGeoByFields2(self, field1, value1, field2, value2):
		return self.GetHydrGeoByFields({field1:value1, field2:value2})
	def GetHydrGeoListByFields(self, fields):
		return self.__GetHydrGeoByFields(fields)
	def GetHydrGeoListByFields1(self, field, value):
		return self.GetHydrGeoListByFields({field:value})
	def GetHydrGeoListByFields2(self, field1, value1, field2, value2):
		return self.GetHydrGeoListByFields({field1:value1, field2:value2})

	#Mine 类型的CRUD操作
	def AddMine(self, mine):
		sql_obj = sql.Mine()
		CbmUtil.CopyAttribs(mine, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteMine(self, id):
		ret=True
		try:
			self.session.query(sql.Mine).filter(sql.Mine.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateMine(self, mine):
		ret=True
		try:
			sql_obj = sql.Mine()
			CbmUtil.CopyAttribs(mine, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.Mine).filter(sql.Mine.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetMineById(self, id):
		query=self.session.query(sql.Mine).filter(sql.Mine.id==id).first()
		obj = Mine()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetMineByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.Mine).filter_by(**fields).first()
		obj = Mine()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetMineList(self):
		query=self.session.query(sql.Mine).all()
		n = len(query)
		obj_list = [Mine() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetMineIds(self):
		query=self.session.query(sql.Mine).all()
		return [obj.id for obj in query]
	def GetMineNames(self):
		query=self.session.query(sql.Mine).all()
		if hasattr(Mine, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreMine(self, objs):
		n = len(objs)
		sql_objs = [sql.Mine() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreMine(self, obj_ids):
		self.session.query(sql.Mine).filter(sql.Mine.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetMineByFields(self, fields):
		query = self.session.query(sql.Mine).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [Mine() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetMineByFields(self, fields):
		objs = self.__GetMineByFields(fields)
		if len(objs) == 0:
			obj = Mine()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetMineByFields1(self, field, value):
		return self.GetMineByFields({field:value})
	def GetMineByFields2(self, field1, value1, field2, value2):
		return self.GetMineByFields({field1:value1, field2:value2})
	def GetMineListByFields(self, fields):
		return self.__GetMineByFields(fields)
	def GetMineListByFields1(self, field, value):
		return self.GetMineListByFields({field:value})
	def GetMineListByFields2(self, field1, value1, field2, value2):
		return self.GetMineListByFields({field1:value1, field2:value2})

	#MineBase 类型的CRUD操作
	def AddMineBase(self, mine_base):
		sql_obj = sql.MineBase()
		CbmUtil.CopyAttribs(mine_base, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteMineBase(self, id):
		ret=True
		try:
			self.session.query(sql.MineBase).filter(sql.MineBase.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateMineBase(self, mine_base):
		ret=True
		try:
			sql_obj = sql.MineBase()
			CbmUtil.CopyAttribs(mine_base, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.MineBase).filter(sql.MineBase.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetMineBaseById(self, id):
		query=self.session.query(sql.MineBase).filter(sql.MineBase.id==id).first()
		obj = MineBase()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetMineBaseByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.MineBase).filter_by(**fields).first()
		obj = MineBase()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetMineBaseList(self):
		query=self.session.query(sql.MineBase).all()
		n = len(query)
		obj_list = [MineBase() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetMineBaseIds(self):
		query=self.session.query(sql.MineBase).all()
		return [obj.id for obj in query]
	def GetMineBaseNames(self):
		query=self.session.query(sql.MineBase).all()
		if hasattr(MineBase, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreMineBase(self, objs):
		n = len(objs)
		sql_objs = [sql.MineBase() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreMineBase(self, obj_ids):
		self.session.query(sql.MineBase).filter(sql.MineBase.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetMineBaseByFields(self, fields):
		query = self.session.query(sql.MineBase).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [MineBase() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetMineBaseByFields(self, fields):
		objs = self.__GetMineBaseByFields(fields)
		if len(objs) == 0:
			obj = MineBase()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetMineBaseByFields1(self, field, value):
		return self.GetMineBaseByFields({field:value})
	def GetMineBaseByFields2(self, field1, value1, field2, value2):
		return self.GetMineBaseByFields({field1:value1, field2:value2})
	def GetMineBaseListByFields(self, fields):
		return self.__GetMineBaseByFields(fields)
	def GetMineBaseListByFields1(self, field, value):
		return self.GetMineBaseListByFields({field:value})
	def GetMineBaseListByFields2(self, field1, value1, field2, value2):
		return self.GetMineBaseListByFields({field1:value1, field2:value2})

	#MineRegion 类型的CRUD操作
	def AddMineRegion(self, mine_region):
		sql_obj = sql.MineRegion()
		CbmUtil.CopyAttribs(mine_region, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteMineRegion(self, id):
		ret=True
		try:
			self.session.query(sql.MineRegion).filter(sql.MineRegion.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateMineRegion(self, mine_region):
		ret=True
		try:
			sql_obj = sql.MineRegion()
			CbmUtil.CopyAttribs(mine_region, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.MineRegion).filter(sql.MineRegion.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetMineRegionById(self, id):
		query=self.session.query(sql.MineRegion).filter(sql.MineRegion.id==id).first()
		obj = MineRegion()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetMineRegionByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.MineRegion).filter_by(**fields).first()
		obj = MineRegion()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetMineRegionList(self):
		query=self.session.query(sql.MineRegion).all()
		n = len(query)
		obj_list = [MineRegion() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetMineRegionIds(self):
		query=self.session.query(sql.MineRegion).all()
		return [obj.id for obj in query]
	def GetMineRegionNames(self):
		query=self.session.query(sql.MineRegion).all()
		if hasattr(MineRegion, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreMineRegion(self, objs):
		n = len(objs)
		sql_objs = [sql.MineRegion() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreMineRegion(self, obj_ids):
		self.session.query(sql.MineRegion).filter(sql.MineRegion.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetMineRegionByFields(self, fields):
		query = self.session.query(sql.MineRegion).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [MineRegion() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetMineRegionByFields(self, fields):
		objs = self.__GetMineRegionByFields(fields)
		if len(objs) == 0:
			obj = MineRegion()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetMineRegionByFields1(self, field, value):
		return self.GetMineRegionByFields({field:value})
	def GetMineRegionByFields2(self, field1, value1, field2, value2):
		return self.GetMineRegionByFields({field1:value1, field2:value2})
	def GetMineRegionListByFields(self, fields):
		return self.__GetMineRegionByFields(fields)
	def GetMineRegionListByFields1(self, field, value):
		return self.GetMineRegionListByFields({field:value})
	def GetMineRegionListByFields2(self, field1, value1, field2, value2):
		return self.GetMineRegionListByFields({field1:value1, field2:value2})

	#PoreFlow 类型的CRUD操作
	def AddPoreFlow(self, pore_flow):
		sql_obj = sql.PoreFlow()
		CbmUtil.CopyAttribs(pore_flow, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeletePoreFlow(self, id):
		ret=True
		try:
			self.session.query(sql.PoreFlow).filter(sql.PoreFlow.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdatePoreFlow(self, pore_flow):
		ret=True
		try:
			sql_obj = sql.PoreFlow()
			CbmUtil.CopyAttribs(pore_flow, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.PoreFlow).filter(sql.PoreFlow.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetPoreFlowById(self, id):
		query=self.session.query(sql.PoreFlow).filter(sql.PoreFlow.id==id).first()
		obj = PoreFlow()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetPoreFlowByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.PoreFlow).filter_by(**fields).first()
		obj = PoreFlow()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetPoreFlowList(self):
		query=self.session.query(sql.PoreFlow).all()
		n = len(query)
		obj_list = [PoreFlow() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetPoreFlowIds(self):
		query=self.session.query(sql.PoreFlow).all()
		return [obj.id for obj in query]
	def GetPoreFlowNames(self):
		query=self.session.query(sql.PoreFlow).all()
		if hasattr(PoreFlow, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMorePoreFlow(self, objs):
		n = len(objs)
		sql_objs = [sql.PoreFlow() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMorePoreFlow(self, obj_ids):
		self.session.query(sql.PoreFlow).filter(sql.PoreFlow.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetPoreFlowByFields(self, fields):
		query = self.session.query(sql.PoreFlow).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [PoreFlow() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetPoreFlowByFields(self, fields):
		objs = self.__GetPoreFlowByFields(fields)
		if len(objs) == 0:
			obj = PoreFlow()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetPoreFlowByFields1(self, field, value):
		return self.GetPoreFlowByFields({field:value})
	def GetPoreFlowByFields2(self, field1, value1, field2, value2):
		return self.GetPoreFlowByFields({field1:value1, field2:value2})
	def GetPoreFlowListByFields(self, fields):
		return self.__GetPoreFlowByFields(fields)
	def GetPoreFlowListByFields1(self, field, value):
		return self.GetPoreFlowListByFields({field:value})
	def GetPoreFlowListByFields2(self, field1, value1, field2, value2):
		return self.GetPoreFlowListByFields({field1:value1, field2:value2})

	#PoreSize 类型的CRUD操作
	def AddPoreSize(self, pore_size):
		sql_obj = sql.PoreSize()
		CbmUtil.CopyAttribs(pore_size, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeletePoreSize(self, id):
		ret=True
		try:
			self.session.query(sql.PoreSize).filter(sql.PoreSize.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdatePoreSize(self, pore_size):
		ret=True
		try:
			sql_obj = sql.PoreSize()
			CbmUtil.CopyAttribs(pore_size, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.PoreSize).filter(sql.PoreSize.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetPoreSizeById(self, id):
		query=self.session.query(sql.PoreSize).filter(sql.PoreSize.id==id).first()
		obj = PoreSize()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetPoreSizeByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.PoreSize).filter_by(**fields).first()
		obj = PoreSize()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetPoreSizeList(self):
		query=self.session.query(sql.PoreSize).all()
		n = len(query)
		obj_list = [PoreSize() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetPoreSizeIds(self):
		query=self.session.query(sql.PoreSize).all()
		return [obj.id for obj in query]
	def GetPoreSizeNames(self):
		query=self.session.query(sql.PoreSize).all()
		if hasattr(PoreSize, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMorePoreSize(self, objs):
		n = len(objs)
		sql_objs = [sql.PoreSize() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMorePoreSize(self, obj_ids):
		self.session.query(sql.PoreSize).filter(sql.PoreSize.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetPoreSizeByFields(self, fields):
		query = self.session.query(sql.PoreSize).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [PoreSize() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetPoreSizeByFields(self, fields):
		objs = self.__GetPoreSizeByFields(fields)
		if len(objs) == 0:
			obj = PoreSize()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetPoreSizeByFields1(self, field, value):
		return self.GetPoreSizeByFields({field:value})
	def GetPoreSizeByFields2(self, field1, value1, field2, value2):
		return self.GetPoreSizeByFields({field1:value1, field2:value2})
	def GetPoreSizeListByFields(self, fields):
		return self.__GetPoreSizeByFields(fields)
	def GetPoreSizeListByFields1(self, field, value):
		return self.GetPoreSizeListByFields({field:value})
	def GetPoreSizeListByFields2(self, field1, value1, field2, value2):
		return self.GetPoreSizeListByFields({field1:value1, field2:value2})

	#ResAbundance 类型的CRUD操作
	def AddResAbundance(self, res_abundance):
		sql_obj = sql.ResAbundance()
		CbmUtil.CopyAttribs(res_abundance, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteResAbundance(self, id):
		ret=True
		try:
			self.session.query(sql.ResAbundance).filter(sql.ResAbundance.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateResAbundance(self, res_abundance):
		ret=True
		try:
			sql_obj = sql.ResAbundance()
			CbmUtil.CopyAttribs(res_abundance, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.ResAbundance).filter(sql.ResAbundance.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetResAbundanceById(self, id):
		query=self.session.query(sql.ResAbundance).filter(sql.ResAbundance.id==id).first()
		obj = ResAbundance()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetResAbundanceByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.ResAbundance).filter_by(**fields).first()
		obj = ResAbundance()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetResAbundanceList(self):
		query=self.session.query(sql.ResAbundance).all()
		n = len(query)
		obj_list = [ResAbundance() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetResAbundanceIds(self):
		query=self.session.query(sql.ResAbundance).all()
		return [obj.id for obj in query]
	def GetResAbundanceNames(self):
		query=self.session.query(sql.ResAbundance).all()
		if hasattr(ResAbundance, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreResAbundance(self, objs):
		n = len(objs)
		sql_objs = [sql.ResAbundance() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreResAbundance(self, obj_ids):
		self.session.query(sql.ResAbundance).filter(sql.ResAbundance.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetResAbundanceByFields(self, fields):
		query = self.session.query(sql.ResAbundance).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [ResAbundance() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetResAbundanceByFields(self, fields):
		objs = self.__GetResAbundanceByFields(fields)
		if len(objs) == 0:
			obj = ResAbundance()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetResAbundanceByFields1(self, field, value):
		return self.GetResAbundanceByFields({field:value})
	def GetResAbundanceByFields2(self, field1, value1, field2, value2):
		return self.GetResAbundanceByFields({field1:value1, field2:value2})
	def GetResAbundanceListByFields(self, fields):
		return self.__GetResAbundanceByFields(fields)
	def GetResAbundanceListByFields1(self, field, value):
		return self.GetResAbundanceListByFields({field:value})
	def GetResAbundanceListByFields2(self, field1, value1, field2, value2):
		return self.GetResAbundanceListByFields({field1:value1, field2:value2})

	#Rock 类型的CRUD操作
	def AddRock(self, rock):
		sql_obj = sql.Rock()
		CbmUtil.CopyAttribs(rock, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteRock(self, id):
		ret=True
		try:
			self.session.query(sql.Rock).filter(sql.Rock.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateRock(self, rock):
		ret=True
		try:
			sql_obj = sql.Rock()
			CbmUtil.CopyAttribs(rock, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.Rock).filter(sql.Rock.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetRockById(self, id):
		query=self.session.query(sql.Rock).filter(sql.Rock.id==id).first()
		obj = Rock()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetRockByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.Rock).filter_by(**fields).first()
		obj = Rock()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetRockList(self):
		query=self.session.query(sql.Rock).all()
		n = len(query)
		obj_list = [Rock() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetRockIds(self):
		query=self.session.query(sql.Rock).all()
		return [obj.id for obj in query]
	def GetRockNames(self):
		query=self.session.query(sql.Rock).all()
		if hasattr(Rock, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreRock(self, objs):
		n = len(objs)
		sql_objs = [sql.Rock() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreRock(self, obj_ids):
		self.session.query(sql.Rock).filter(sql.Rock.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetRockByFields(self, fields):
		query = self.session.query(sql.Rock).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [Rock() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetRockByFields(self, fields):
		objs = self.__GetRockByFields(fields)
		if len(objs) == 0:
			obj = Rock()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetRockByFields1(self, field, value):
		return self.GetRockByFields({field:value})
	def GetRockByFields2(self, field1, value1, field2, value2):
		return self.GetRockByFields({field1:value1, field2:value2})
	def GetRockListByFields(self, fields):
		return self.__GetRockByFields(fields)
	def GetRockListByFields1(self, field, value):
		return self.GetRockListByFields({field:value})
	def GetRockListByFields2(self, field1, value1, field2, value2):
		return self.GetRockListByFields({field1:value1, field2:value2})

	#SysInfo 类型的CRUD操作
	def AddSysInfo(self, sys_info):
		sql_obj = sql.SysInfo()
		CbmUtil.CopyAttribs(sys_info, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteSysInfo(self, id):
		ret=True
		try:
			self.session.query(sql.SysInfo).filter(sql.SysInfo.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateSysInfo(self, sys_info):
		ret=True
		try:
			sql_obj = sql.SysInfo()
			CbmUtil.CopyAttribs(sys_info, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.SysInfo).filter(sql.SysInfo.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetSysInfoById(self, id):
		query=self.session.query(sql.SysInfo).filter(sql.SysInfo.id==id).first()
		obj = SysInfo()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetSysInfoByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.SysInfo).filter_by(**fields).first()
		obj = SysInfo()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetSysInfoList(self):
		query=self.session.query(sql.SysInfo).all()
		n = len(query)
		obj_list = [SysInfo() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetSysInfoIds(self):
		query=self.session.query(sql.SysInfo).all()
		return [obj.id for obj in query]
	def GetSysInfoNames(self):
		query=self.session.query(sql.SysInfo).all()
		if hasattr(SysInfo, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreSysInfo(self, objs):
		n = len(objs)
		sql_objs = [sql.SysInfo() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreSysInfo(self, obj_ids):
		self.session.query(sql.SysInfo).filter(sql.SysInfo.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetSysInfoByFields(self, fields):
		query = self.session.query(sql.SysInfo).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [SysInfo() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetSysInfoByFields(self, fields):
		objs = self.__GetSysInfoByFields(fields)
		if len(objs) == 0:
			obj = SysInfo()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetSysInfoByFields1(self, field, value):
		return self.GetSysInfoByFields({field:value})
	def GetSysInfoByFields2(self, field1, value1, field2, value2):
		return self.GetSysInfoByFields({field1:value1, field2:value2})
	def GetSysInfoListByFields(self, fields):
		return self.__GetSysInfoByFields(fields)
	def GetSysInfoListByFields1(self, field, value):
		return self.GetSysInfoListByFields({field:value})
	def GetSysInfoListByFields2(self, field1, value1, field2, value2):
		return self.GetSysInfoListByFields({field1:value1, field2:value2})

	#TechMode 类型的CRUD操作
	def AddTechMode(self, tech_mode):
		sql_obj = sql.TechMode()
		CbmUtil.CopyAttribs(tech_mode, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteTechMode(self, id):
		ret=True
		try:
			self.session.query(sql.TechMode).filter(sql.TechMode.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateTechMode(self, tech_mode):
		ret=True
		try:
			sql_obj = sql.TechMode()
			CbmUtil.CopyAttribs(tech_mode, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.TechMode).filter(sql.TechMode.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetTechModeById(self, id):
		query=self.session.query(sql.TechMode).filter(sql.TechMode.id==id).first()
		obj = TechMode()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetTechModeByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.TechMode).filter_by(**fields).first()
		obj = TechMode()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetTechModeList(self):
		query=self.session.query(sql.TechMode).all()
		n = len(query)
		obj_list = [TechMode() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetTechModeIds(self):
		query=self.session.query(sql.TechMode).all()
		return [obj.id for obj in query]
	def GetTechModeNames(self):
		query=self.session.query(sql.TechMode).all()
		if hasattr(TechMode, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreTechMode(self, objs):
		n = len(objs)
		sql_objs = [sql.TechMode() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreTechMode(self, obj_ids):
		self.session.query(sql.TechMode).filter(sql.TechMode.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetTechModeByFields(self, fields):
		query = self.session.query(sql.TechMode).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [TechMode() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetTechModeByFields(self, fields):
		objs = self.__GetTechModeByFields(fields)
		if len(objs) == 0:
			obj = TechMode()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetTechModeByFields1(self, field, value):
		return self.GetTechModeByFields({field:value})
	def GetTechModeByFields2(self, field1, value1, field2, value2):
		return self.GetTechModeByFields({field1:value1, field2:value2})
	def GetTechModeListByFields(self, fields):
		return self.__GetTechModeByFields(fields)
	def GetTechModeListByFields1(self, field, value):
		return self.GetTechModeListByFields({field:value})
	def GetTechModeListByFields2(self, field1, value1, field2, value2):
		return self.GetTechModeListByFields({field1:value1, field2:value2})

	#Technology 类型的CRUD操作
	def AddTechnology(self, technology):
		sql_obj = sql.Technology()
		CbmUtil.CopyAttribs(technology, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteTechnology(self, id):
		ret=True
		try:
			self.session.query(sql.Technology).filter(sql.Technology.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateTechnology(self, technology):
		ret=True
		try:
			sql_obj = sql.Technology()
			CbmUtil.CopyAttribs(technology, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.Technology).filter(sql.Technology.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetTechnologyById(self, id):
		query=self.session.query(sql.Technology).filter(sql.Technology.id==id).first()
		obj = Technology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetTechnologyByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.Technology).filter_by(**fields).first()
		obj = Technology()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetTechnologyList(self):
		query=self.session.query(sql.Technology).all()
		n = len(query)
		obj_list = [Technology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetTechnologyIds(self):
		query=self.session.query(sql.Technology).all()
		return [obj.id for obj in query]
	def GetTechnologyNames(self):
		query=self.session.query(sql.Technology).all()
		if hasattr(Technology, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreTechnology(self, objs):
		n = len(objs)
		sql_objs = [sql.Technology() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreTechnology(self, obj_ids):
		self.session.query(sql.Technology).filter(sql.Technology.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetTechnologyByFields(self, fields):
		query = self.session.query(sql.Technology).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [Technology() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetTechnologyByFields(self, fields):
		objs = self.__GetTechnologyByFields(fields)
		if len(objs) == 0:
			obj = Technology()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetTechnologyByFields1(self, field, value):
		return self.GetTechnologyByFields({field:value})
	def GetTechnologyByFields2(self, field1, value1, field2, value2):
		return self.GetTechnologyByFields({field1:value1, field2:value2})
	def GetTechnologyListByFields(self, fields):
		return self.__GetTechnologyByFields(fields)
	def GetTechnologyListByFields1(self, field, value):
		return self.GetTechnologyListByFields({field:value})
	def GetTechnologyListByFields2(self, field1, value1, field2, value2):
		return self.GetTechnologyListByFields({field1:value1, field2:value2})

	#TopoGeo 类型的CRUD操作
	def AddTopoGeo(self, topo_geo):
		sql_obj = sql.TopoGeo()
		CbmUtil.CopyAttribs(topo_geo, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteTopoGeo(self, id):
		ret=True
		try:
			self.session.query(sql.TopoGeo).filter(sql.TopoGeo.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateTopoGeo(self, topo_geo):
		ret=True
		try:
			sql_obj = sql.TopoGeo()
			CbmUtil.CopyAttribs(topo_geo, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.TopoGeo).filter(sql.TopoGeo.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetTopoGeoById(self, id):
		query=self.session.query(sql.TopoGeo).filter(sql.TopoGeo.id==id).first()
		obj = TopoGeo()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetTopoGeoByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.TopoGeo).filter_by(**fields).first()
		obj = TopoGeo()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetTopoGeoList(self):
		query=self.session.query(sql.TopoGeo).all()
		n = len(query)
		obj_list = [TopoGeo() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetTopoGeoIds(self):
		query=self.session.query(sql.TopoGeo).all()
		return [obj.id for obj in query]
	def GetTopoGeoNames(self):
		query=self.session.query(sql.TopoGeo).all()
		if hasattr(TopoGeo, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreTopoGeo(self, objs):
		n = len(objs)
		sql_objs = [sql.TopoGeo() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreTopoGeo(self, obj_ids):
		self.session.query(sql.TopoGeo).filter(sql.TopoGeo.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetTopoGeoByFields(self, fields):
		query = self.session.query(sql.TopoGeo).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [TopoGeo() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetTopoGeoByFields(self, fields):
		objs = self.__GetTopoGeoByFields(fields)
		if len(objs) == 0:
			obj = TopoGeo()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetTopoGeoByFields1(self, field, value):
		return self.GetTopoGeoByFields({field:value})
	def GetTopoGeoByFields2(self, field1, value1, field2, value2):
		return self.GetTopoGeoByFields({field1:value1, field2:value2})
	def GetTopoGeoListByFields(self, fields):
		return self.__GetTopoGeoByFields(fields)
	def GetTopoGeoListByFields1(self, field, value):
		return self.GetTopoGeoListByFields({field:value})
	def GetTopoGeoListByFields2(self, field1, value1, field2, value2):
		return self.GetTopoGeoListByFields({field1:value1, field2:value2})

	#Tunnel 类型的CRUD操作
	def AddTunnel(self, tunnel):
		sql_obj = sql.Tunnel()
		CbmUtil.CopyAttribs(tunnel, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteTunnel(self, id):
		ret=True
		try:
			self.session.query(sql.Tunnel).filter(sql.Tunnel.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateTunnel(self, tunnel):
		ret=True
		try:
			sql_obj = sql.Tunnel()
			CbmUtil.CopyAttribs(tunnel, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.Tunnel).filter(sql.Tunnel.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetTunnelById(self, id):
		query=self.session.query(sql.Tunnel).filter(sql.Tunnel.id==id).first()
		obj = Tunnel()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetTunnelByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.Tunnel).filter_by(**fields).first()
		obj = Tunnel()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetTunnelList(self):
		query=self.session.query(sql.Tunnel).all()
		n = len(query)
		obj_list = [Tunnel() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetTunnelIds(self):
		query=self.session.query(sql.Tunnel).all()
		return [obj.id for obj in query]
	def GetTunnelNames(self):
		query=self.session.query(sql.Tunnel).all()
		if hasattr(Tunnel, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreTunnel(self, objs):
		n = len(objs)
		sql_objs = [sql.Tunnel() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreTunnel(self, obj_ids):
		self.session.query(sql.Tunnel).filter(sql.Tunnel.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetTunnelByFields(self, fields):
		query = self.session.query(sql.Tunnel).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [Tunnel() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetTunnelByFields(self, fields):
		objs = self.__GetTunnelByFields(fields)
		if len(objs) == 0:
			obj = Tunnel()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetTunnelByFields1(self, field, value):
		return self.GetTunnelByFields({field:value})
	def GetTunnelByFields2(self, field1, value1, field2, value2):
		return self.GetTunnelByFields({field1:value1, field2:value2})
	def GetTunnelListByFields(self, fields):
		return self.__GetTunnelByFields(fields)
	def GetTunnelListByFields1(self, field, value):
		return self.GetTunnelListByFields({field:value})
	def GetTunnelListByFields2(self, field1, value1, field2, value2):
		return self.GetTunnelListByFields({field1:value1, field2:value2})

	#WorkArea 类型的CRUD操作
	def AddWorkArea(self, work_area):
		sql_obj = sql.WorkArea()
		CbmUtil.CopyAttribs(work_area, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteWorkArea(self, id):
		ret=True
		try:
			self.session.query(sql.WorkArea).filter(sql.WorkArea.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateWorkArea(self, work_area):
		ret=True
		try:
			sql_obj = sql.WorkArea()
			CbmUtil.CopyAttribs(work_area, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.WorkArea).filter(sql.WorkArea.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetWorkAreaById(self, id):
		query=self.session.query(sql.WorkArea).filter(sql.WorkArea.id==id).first()
		obj = WorkArea()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetWorkAreaByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.WorkArea).filter_by(**fields).first()
		obj = WorkArea()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetWorkAreaList(self):
		query=self.session.query(sql.WorkArea).all()
		n = len(query)
		obj_list = [WorkArea() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetWorkAreaIds(self):
		query=self.session.query(sql.WorkArea).all()
		return [obj.id for obj in query]
	def GetWorkAreaNames(self):
		query=self.session.query(sql.WorkArea).all()
		if hasattr(WorkArea, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreWorkArea(self, objs):
		n = len(objs)
		sql_objs = [sql.WorkArea() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreWorkArea(self, obj_ids):
		self.session.query(sql.WorkArea).filter(sql.WorkArea.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetWorkAreaByFields(self, fields):
		query = self.session.query(sql.WorkArea).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [WorkArea() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetWorkAreaByFields(self, fields):
		objs = self.__GetWorkAreaByFields(fields)
		if len(objs) == 0:
			obj = WorkArea()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetWorkAreaByFields1(self, field, value):
		return self.GetWorkAreaByFields({field:value})
	def GetWorkAreaByFields2(self, field1, value1, field2, value2):
		return self.GetWorkAreaByFields({field1:value1, field2:value2})
	def GetWorkAreaListByFields(self, fields):
		return self.__GetWorkAreaByFields(fields)
	def GetWorkAreaListByFields1(self, field, value):
		return self.GetWorkAreaListByFields({field:value})
	def GetWorkAreaListByFields2(self, field1, value1, field2, value2):
		return self.GetWorkAreaListByFields({field1:value1, field2:value2})

	#WorkSurf 类型的CRUD操作
	def AddWorkSurf(self, work_surf):
		sql_obj = sql.WorkSurf()
		CbmUtil.CopyAttribs(work_surf, sql_obj)
		self.session.add(sql_obj)
		self.session.flush()
		self.session.commit()
		return sql_obj.id
	def DeleteWorkSurf(self, id):
		ret=True
		try:
			self.session.query(sql.WorkSurf).filter(sql.WorkSurf.id==id).delete()
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def UpdateWorkSurf(self, work_surf):
		ret=True
		try:
			sql_obj = sql.WorkSurf()
			CbmUtil.CopyAttribs(work_surf, sql_obj)
			attribs = CbmUtil.GetAttribs(sql_obj)
			del attribs['id']
			self.session.query(sql.WorkSurf).filter(sql.WorkSurf.id==sql_obj.id).update(attribs)
			self.session.commit()
		except Exception, e:
			#print e
			ret=False
		return ret
	def GetWorkSurfById(self, id):
		query=self.session.query(sql.WorkSurf).filter(sql.WorkSurf.id==id).first()
		obj = WorkSurf()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetWorkSurfByForeignKey(self, fkey, id):
		key = fkey if fkey.endswith('_id') else '%s_id' % fkey
		fields = {key:id}
		query=self.session.query(sql.WorkSurf).filter_by(**fields).first()
		obj = WorkSurf()
		if query is None:
			obj.id = -1
		else:
			CbmUtil.CopyAttribs(query, obj)
		return obj
	def GetWorkSurfList(self):
		query=self.session.query(sql.WorkSurf).all()
		n = len(query)
		obj_list = [WorkSurf() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(query[i], obj_list[i])
		return obj_list
	def GetWorkSurfIds(self):
		query=self.session.query(sql.WorkSurf).all()
		return [obj.id for obj in query]
	def GetWorkSurfNames(self):
		query=self.session.query(sql.WorkSurf).all()
		if hasattr(WorkSurf, 'name'):
			return [obj.name for obj in query]
		else:
			return []
	def AddMoreWorkSurf(self, objs):
		n = len(objs)
		sql_objs = [sql.WorkSurf() for i in range(n)]
		for i in range(n):
			CbmUtil.CopyAttribs(objs[i], sql_objs[i])
			self.session.add(sql_objs[i])
		self.session.flush()
		self.session.commit()
	def DeleteMoreWorkSurf(self, obj_ids):
		self.session.query(sql.WorkSurf).filter(sql.WorkSurf.id.in_(obj_ids)).delete()
		self.session.commit()
	def __GetWorkSurfByFields(self, fields):
		query = self.session.query(sql.WorkSurf).filter_by(**fields).all()
		if len(query) == 0:
			return []
		else:
			n = len(query)
			obj_list = [WorkSurf() for i in range(n)]
			for i in range(n):
				CbmUtil.CopyAttribs(query[i], obj_list[i])
			return obj_list
	def GetWorkSurfByFields(self, fields):
		objs = self.__GetWorkSurfByFields(fields)
		if len(objs) == 0:
			obj = WorkSurf()
			obj.id = -1
			return obj
		else:
			return objs[0]
	def GetWorkSurfByFields1(self, field, value):
		return self.GetWorkSurfByFields({field:value})
	def GetWorkSurfByFields2(self, field1, value1, field2, value2):
		return self.GetWorkSurfByFields({field1:value1, field2:value2})
	def GetWorkSurfListByFields(self, fields):
		return self.__GetWorkSurfByFields(fields)
	def GetWorkSurfListByFields1(self, field, value):
		return self.GetWorkSurfListByFields({field:value})
	def GetWorkSurfListByFields2(self, field1, value1, field2, value2):
		return self.GetWorkSurfListByFields({field1:value1, field2:value2})

