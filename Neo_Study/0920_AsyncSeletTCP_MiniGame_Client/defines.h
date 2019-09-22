#pragma once

//��ũ�� ����� �ݵ�� ���ٿ� ���� �Ǿ����.
#define SAFE_DELETE( p ) { if( p ) { delete ( p ); ( p ) = NULL; } }
#define SAFE_DELETE_ARRAY( p ) { if( p ) { delete[] ( p ); ( p ) = NULL; } }
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }

//�̱��� ������ִ� ��ũ��
#define DECLARE_SINGLE(Type) \
	private: \
		static Type*	m_pInst; \
	public: \
		static Type*	GetInstance()\
		{\
			if(!m_pInst)\
				m_pInst = new Type();\
			return m_pInst;\
        }\
		static void DestroyInst() \
		{\
			SAFE_DELETE(m_pInst);\
		}\
		private: \
			Type(); \
			~Type();

// �̱��� ����.(CPP�� �־��ָ��.) �ݵ�� ����ؾ��ϱ⶧��.
#define DEFINITION_SINGLE(Type) Type* Type::m_pInst = NULL;

//�̱����� �������� ��ũ��
#define GET_SINGLE(Type) Type::GetInstance()

//�̱��� ���� ��ũ��
#define	DESTROY_SINGLE(Type) Type::DestroyInst()