// ZoomVoiceRecorderUpdateai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "stdafx.h"

#include "ZoomVoiceRecorderUpdateai.h"


//#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

int main()
{
    std::cout << "Init ongoing...\n";


	ZOOM_SDK_NAMESPACE::InitParam initParam;
	initParam.strWebDomain = L"https://zoom.us";
	initParam.strSupportUrl = L"https://zoom.us";

	//set language id
	initParam.emLanguageID = ZOOM_SDK_NAMESPACE::LANGUAGE_English;
	//change icon
	//initParam.uiWindowIconSmallID = IDI_ICON_LOGO;
	//initParam.uiWindowIconBigID = IDI_ICON_LOGO;
	initParam.hResInstance = GetModuleHandle(NULL);
	initParam.enableLogByDefault = true;
	initParam.enableGenerateDump = true;
	
	//bool customiezed_ui_mode = false;
	//if (m_chkCustomizedUI)
	//	customiezed_ui_mode = m_chkCustomizedUI->GetCheck();
	//if (customiezed_ui_mode)
	initParam.obConfigOpts.optionalFeatures = false;
	//CInitSDKWorkFlow   m_initSDKWorkFlow;
	ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::InitSDK(initParam);
	if (ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS != err)
	{
		std::cout << err << "- ** Fail: Zoom SDK Init!" << std::endl;
	}
	else
	{
		std::cout << err << "- Zoom SDK Init Success !!" << std::endl;
		std::wstring strToken = L"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhcHBLZXkiOiI5a3FGUzJDa0xjQ1JNbWR2ZGJQUUhVbEVEeFdlM1J5SzlvSUciLCJpYXQiOjE2MTUyMTgyMTcsImV4cCI6MTYxNzg5NjU2MSwidG9rZW5FeHAiOjE2MTc4OTY1NjF9.8Fn_SVzKiPwn4vfOWzacK-vsc4uKG3N_qwc7Q27xScE";
		if (strToken.size() > 0)
		{
			ZOOM_SDK_NAMESPACE::AuthContext param;
			param.jwt_token = strToken.c_str();
			ZOOM_SDK_NAMESPACE::IAuthService* _auth_service;
			ZOOM_SDK_NAMESPACE::CreateAuthService(&_auth_service);
			if (_auth_service)
			{
				err = _auth_service->SDKAuth(param);
				Sleep(5000);
				if (ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS != err)
				{
					std::cout << err << "- ** auth sdk failed" << std::endl;
				}
				else
				{
					std::cout << err << "- Zoom SDK Auth Success !!" << std::endl;
				}
			}
			else {
				std::cout << "** Auth Service Creation Falied!" << std::endl;
			}

		}
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
