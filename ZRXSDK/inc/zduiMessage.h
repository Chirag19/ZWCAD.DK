#ifndef _zduiMessage_h
#define _zduiMessage_h
#pragma pack (push, 8)

#pragma once

typedef enum {
    kAdUiNotify_Nothing,

    kAdUiNotify_Generic,

    kAdUiNotify_AppMainWindow,

    kAdUiNotify_AppResourceInstance,

    kAdUiNotify_AutoLoad,
    kAdUiNotify_Reload,

    kAdUiNotify_GetTipSupport,

    kAdUiNotify_GetTipText,

    kAdUiNotify_GetTipRect,

    kAdUiNotify_HitTipRect,

    kAdUiNotify_DrawTip,

    kAdUiNotify_DrawTipText,

    kAdUiNotify_UpdateTip,

    kAdUiNotify_HideWindow,
    kAdUiNotify_ShowWindow,

    kAdUiNotify_RestoreFocus,

    kAdUiNotify_Change,

    kAdUiNotify_NotValid,

    kAdUiNotify_Valid,

    kAdUiNotify_Validate,

    kAdUiNotify_CommandState,

} ZDUI_NOTIFY;

typedef enum {
    kAdUiReply_Nothing,

    kAdUiReply_Ok,

    kAdUiReply_NotValid,

    kAdUiReply_Valid,

    kAdUiReply_TextTip,

    kAdUiReply_ToolTip,

    kAdUiReply_DrawTip,

} ZDUI_REPLY;

typedef enum {
    kAdUiCommand_Cancelled = -1,

    kAdUiCommand_Completed,

    kAdUiCommand_Begun,

} ZDUI_COMMAND_STATE;

class ZDUI_PORT CZdUiDrawTipText {
public:
                CZdUiDrawTipText (CDC& dc, CRect& rect, CString& text);

public:
        CDC&    m_dc;
        CRect&  m_rect;
        CString& m_text;
};



const UINT ZDUI_PORT ZdUiMessage ();

ZDUI_NOTIFY ZDUI_PORT ZdUiNotification (WPARAM wp);

#ifndef _WIN64
ZDUI_REPLY ZDUI_PORT ZdUiNotify (CWnd& w, UINT id, ZDUI_NOTIFY n, DWORD_PTR lParam);
ZDUI_REPLY ZDUI_PORT ZdUiNotify (CWnd* w, UINT id, ZDUI_NOTIFY n, DWORD_PTR lParam);
#else
ZDUI_REPLY ZDUI_PORT ZdUiNotify (CWnd& w, UINT id, ZDUI_NOTIFY n, LPARAM lParam);
ZDUI_REPLY ZDUI_PORT ZdUiNotify (CWnd* w, UINT id, ZDUI_NOTIFY n, LPARAM lParam);
#endif

UINT ZDUI_PORT ZdUiNotifyId (WPARAM wp);

#ifndef _WIN64
BOOL ZDUI_PORT ZdUiPostNotify (CWnd& w, UINT id, ZDUI_NOTIFY n, DWORD_PTR lParam);
BOOL ZDUI_PORT ZdUiPostNotify (CWnd* w, UINT id, ZDUI_NOTIFY n, DWORD_PTR lParam);
#else
BOOL ZDUI_PORT ZdUiPostNotify (CWnd& w, UINT id, ZDUI_NOTIFY n, LPARAM lParam);
BOOL ZDUI_PORT ZdUiPostNotify (CWnd* w, UINT id, ZDUI_NOTIFY n, LPARAM lParam);
#endif

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
