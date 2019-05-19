#ifndef YAML_PARSER_H_INCLUDED
#define YAML_PARSER_H_INCLUDED

typedef struct yaml_document_s yaml_document_t;
typedef struct yaml_node_s yaml_node_t;

#include "SharedBase.h"
#include "Logging.h"

class mCYamlParser
{
    public:
        mCYamlParser( mCLoggerBase & a_Logger );

    public:
        GELPVoid LoadYaml( bCString const & a_strFile, bCString const & a_strTargetType, bTObjArray<bCString> const * a_arrClassPrefixes = 0 );
        GELPVoid LoadYaml( bCString const & a_strFile, bCPropertyObjectTypeBase const & a_Type, bTObjArray<bCString> const * a_arrClassPrefixes = 0 );

        template <typename T>
        T * LoadYaml( bCString const & a_strFile, bTObjArray<bCString> const * a_arrClassPrefixes = 0 );

        template <typename T>
        bTPtrArray<T *> * LoadYamlSequence( bCString const & a_strFile, bTObjArray<bCString> const * a_arrClassPrefixes = 0 );

        template <typename T>
        GEBool LoadYamlSequence( bCString const & a_strFile, bTPtrArray<T *> & a_oArray, bTObjArray<bCString> const * a_arrClassPrefixes );

        template <typename T>
        bTObjArray<bTAutoPOSmartPtr<T>> * LoadYamlSequenceAuto( bCString const & a_strFile, bTObjArray<bCString> const * a_arrClassPrefixes = 0 );

    private:
        static GEInt YamlFileReadHandler( GELPVoid data, GELPByte buffer, size_t size, size_t *size_read );

        struct mSReadState
        {
            mSReadState()
                : m_pNode(0), m_pData(0), m_pPropertyType(0)
            {
            }

            mSReadState(yaml_node_t * a_pNode, GELPVoid a_pData, bCPropertyTypeBase * a_pPropertyType)
                : m_pNode(a_pNode), m_pData(a_pData), m_pPropertyType(a_pPropertyType)
            {
            }

            mSReadState(yaml_node_t * a_pNode, GELPVoid a_pData, bCString a_strClassName)
                : m_pNode(a_pNode), m_pData(a_pData), m_pPropertyType(0), m_strClassName(a_strClassName)
            {
            }

            // Current node
            yaml_node_t * m_pNode;
            // Memory location to store the parsed data to, or 0, if the current node is the root node.
            GELPVoid m_pData;
            // Property corresponding to the current node, or 0, if there is no corresponding property (root node, array members).
            bCPropertyTypeBase * m_pPropertyType;
            // Type corresponding to the current node, which is used when m_pPropertyType is 0.
            bCString m_strClassName;
        };

        struct mSReadContext
        {
            yaml_document_t * m_pDocument;
            bTObjStack<mSReadState> m_arrState;
            bTObjArray<bCString> m_arrClassPrefixes;

            void PushState(mSReadState const & a_State)
            {
                m_arrState.Add(a_State);
            }

            void PopState()
            {
                m_arrState.RemoveAt(m_arrState.GetCount() - 1);
            }

            mSReadState const & PeekState() const
            {
                return m_arrState.Peek();
            }

            GELPVoid GetData()
            {
                return PeekState().m_pData;
            }

            void SetData(GELPVoid a_pData)
            {
                m_arrState.Peek().m_pData = a_pData;
            }

            bCPropertyTypeBase * GetPropertyType()
            {
                return PeekState().m_pPropertyType;
            }

            bCString const & GetClassName() const
            {
                mSReadState const & State = PeekState();
                return State.m_pPropertyType != 0 ? State.m_pPropertyType->GetPropertyClassName() : State.m_strClassName;
            }

            void InitClassPrefixes( bTObjArray<bCString> const * a_arrClassPrefixes )
            {
                m_arrClassPrefixes.Add("");
                if(a_arrClassPrefixes)
                {
                    GE_ARRAY_FOR_EACH_CONST( bCString, Prefix, (*a_arrClassPrefixes) )
                    {
                        m_arrClassPrefixes.Add(*Prefix);
                    }
                }
                m_arrClassPrefixes.Add("mC");
                m_arrClassPrefixes.Add("gC");
                m_arrClassPrefixes.Add("eC");
                m_arrClassPrefixes.Add("bC");
            }
        };

        bEResult ReadNode(mSReadContext & a_Context, yaml_node_t const * a_pNode);
        bEResult ReadScalarNode(mSReadContext & a_Context, yaml_node_t const * a_pNode);
        bEResult ReadSequenceNode(mSReadContext & a_Context, yaml_node_t const * a_pNode);
        bEResult ReadMappingNode(mSReadContext & a_Context, yaml_node_t const * a_pNode);

        bEResult LogError(GELPCChar a_strFormat, ...);
        void PrintBacktrace(mSReadContext const & a_Context);

    private:
        mCLoggerBase & m_Logger;
        bCString m_strFile;

    private:
        mCYamlParser( mCYamlParser const & ); // = delete

    private:
        mCYamlParser & operator = ( mCYamlParser const & ); // = delete
};

#include "YamlParser.inl"

#endif