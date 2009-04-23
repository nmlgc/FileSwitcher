#pragma once
#include "stdafx.h"
#include "EditFile.h"
#include "FileSwitcher.h"
#include "Window.h"

#include <windows.h>
#include <TCHAR.H>
#include <commctrl.h>
#include <resource.h>
#include <shellapi.h>


class FileListView
{
public:
	FileListView(void);
	~FileListView(void) {}

	void init(options_t *options, HINSTANCE hInst, HWND hParent, HWND hListView);

	LRESULT notify(WPARAM wParam, LPARAM lParam);

	int getCurrentSelectedIndex(void);
	EditFile *getCurrentEditFile(void);
	
	void sortItems();
	void sortItems(int currentSortOrder);
	int getCurrentSortOrder(void);

	static int CALLBACK listViewComparer(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

	

private:
	
	HWND		_hListView;
	HWND        _hParentWindow;
	HWND        _hHeader;
	HINSTANCE	_hInstance;

	int			_currentSortOrder;
	

	HBITMAP     _bmpSortUp;
	HBITMAP     _bmpSortDown;

	void updateHeader(void);

};
