#pragma once
//메크로 기능은 반드시 한줄에 정의 되어야함.
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

//레졸루션
#define GETREOULUTION CCore::GetInstance()->GetResolution()

#define WINDOWHANDLE CCore::GetInstance()->GetWindowHandle()

#define KEYDOWN(key)	CInputManager::GetInstance()->KeyDown(key)
#define KEYPRESS(key)	CInputManager::GetInstance()->KeyPress(key)
#define KEYUP(key)		CInputManager::GetInstance()->KeyUp(key)