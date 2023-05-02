#include<Windows.h>
#include<iostream>
#include<string>

int main(void) {
	
	STARTUPINFOW si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	
		if (!CreateProcessW(
		L"C:\\Windows\\notepad.exe",
		NULL,
		NULL,
		NULL,
		FALSE,
		BELOW_NORMAL_PRIORITY_CLASS,
		NULL,
		NULL,
		&si,
		&pi)) {
		printf("(-) Could not exicute process, ERR: %ld", GetLastError());
		return EXIT_FAILURE;
	}
	std::string s = "PID: ";
	s += std::to_string(pi.dwProcessId);
	std::wstring stemp = std::wstring(s.begin(), s.end());
	LPCWSTR sw = stemp.c_str();

	MessageBoxW(
		NULL,
		sw,
		L"PID",
		MB_OK| MB_ICONASTERISK
	);

	return EXIT_SUCCESS;
}