/*
 Legal Notice: Some portions of the source code contained in this file were
 derived from the source code of Encryption for the Masses 2.02a, which is
 Copyright (c) 1998-2000 Paul Le Roux and which is governed by the 'License
 Agreement for Encryption for the Masses'. Modifications and additions to
 the original source code (contained in this file) and all other portions
 of this file are Copyright (c) 2003-2008 TrueCrypt Developers Association
 and are governed by the TrueCrypt License 3.0 the full text of which is
 contained in the file License.txt included in TrueCrypt binary and source
 code distribution packages. */

#ifndef PASSWORD_H
#define PASSWORD_H

// User text input limits
#define MIN_PASSWORD			1		// Minimum possible password length
#define MAX_PASSWORD			64		// Maximum possible password length
#define MAX_PIM				10		// Maximum allowed digits in a PIM (enough for 32-bit value)
#define MAX_BOOT_PIM			5		// Maximum allowed digits in a PIM for boot (enough for 16-bit value)
#define MAX_BOOT_PIM_VALUE	65535

#define PASSWORD_LEN_WARNING	20		// Display a warning when a password is shorter than this

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	// Modifying this structure can introduce incompatibility with previous versions
	unsigned __int32 Length;
	unsigned char Text[MAX_PASSWORD + 1];
	char Pad[3]; // keep 64-bit alignment
} Password;

#if defined(_WIN32) && !defined(TC_WINDOWS_DRIVER)

void VerifyPasswordAndUpdate ( HWND hwndDlg , HWND hButton , HWND hPassword , HWND hVerify , unsigned char *szPassword , char *szVerify, BOOL keyFilesEnabled );
BOOL CheckPasswordLength (HWND hwndDlg, HWND hwndItem, int pin, BOOL bForBoot);		
BOOL CheckPasswordCharEncoding (HWND hPassword, Password *ptrPw);			
int ChangePwd (const char *lpszVolume, Password *oldPassword, int old_pkcs5, int old_pin, BOOL truecryptMode, Password *newPassword, int pkcs5, int pin, int wipePassCount, HWND hwndDlg);

#endif	// defined(_WIN32) && !defined(TC_WINDOWS_DRIVER)

#ifdef __cplusplus
}
#endif

#endif	// PASSWORD_H
