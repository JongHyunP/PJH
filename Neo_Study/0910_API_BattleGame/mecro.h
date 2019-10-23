#pragma once


/**
 * @file mecro.h
 * @brief 매크로 헤더.
 * @details  헤더.
 */

 /**
  * @brief 매크로 헤더
  * @details 프로젝트 내의 매크로 정의.
  * @author JongHyun Park, whdgus1590@naver.com
  * @date 2019-10
  * @version 0.0.1
  */

#define SAFE_DELETE( p ) { if( p ) { delete ( p ); ( p ) = NULL; } }
#define SAFE_DELETE_ARRAY( p ) { if( p ) { delete[] ( p ); ( p ) = NULL; } }
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }

  //싱글톤 만들어주는 매크로
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

// 싱글톤 정의.(CPP에 넣어주면됨.) 반드시 사용해야하기때문.
#define DEFINITION_SINGLE(Type) Type* Type::m_pInst = NULL;

//싱글톤을 가져오는 메크로
#define GET_SINGLE(Type) Type::GetInstance()

//싱글톤 제거 메크로
#define	DESTROY_SINGLE(Type) Type::DestroyInst()


