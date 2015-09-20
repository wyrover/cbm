#pragma once

#include "Types.h"

namespace orm
{
    namespace helper
    {
        namespace internal
        {
            template<typename Klass>
            RecordPtrListPtr _find_many( Query* q )
            {
                RowSet rs;
                if( !get_db()->query( q->build_select(), rs ) || rs.empty() ) return RecordPtrListPtr();

                RecordPtrListPtr objs( new RecordPtrList() );
                for( RowSet::iterator itr = rs.begin(); itr != rs.end(); ++itr )
                {
                    RecordPtr obj( Klass::Create() );
                    if( obj->fetchByRow( *itr ) )
                    {
                        objs->push_back( obj );
                    }
                }
                return objs->empty() ? RecordPtrListPtr() : objs;
            }
        }

        template<typename Klass>
        RecordPtr _find_one( Query* q )
        {
            q->limit( 1 );
            RecordPtrListPtr objs = orm::helper::internal::_find_many<Klass>( q );
            return ( objs == 0 || objs->empty() ) ? RecordPtr() : ( *objs )[0];
        }
        template<typename Klass>
        RecordPtrListPtr _find_many( Query* q )
        {
            RecordPtrListPtr objs = orm::helper::internal::_find_many<Klass>( q );
            return ( objs == 0 || objs->empty() ) ? RecordPtrListPtr() : objs;
        }
        template<typename Klass>
        RecordPtr _findById( int id )
        {
            QueryPtr query( Query::From<Klass>() );
            query->where( PKEY( Klass::Table() ), Utils::int_to_cstring( id ) )->limit( 1 );
            return orm::helper::_find_one<Klass>( query.get() );
        }
        template<typename Klass>
        RecordPtr _findFirst()
        {
            QueryPtr query( Query::From<Klass>() );
            return orm::helper::_find_one<Klass>( query.get() );
        }
        template<typename Klass>
        RecordPtrListPtr _findAll()
        {
            QueryPtr query( Query::From<Klass>() );
            return orm::helper::_find_many<Klass>( query.get() );
        }
    }

}