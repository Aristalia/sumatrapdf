/* Copyright 2019 the SumatraPDF project authors (see AUTHORS file).
   License: Simplified BSD (see COPYING.BSD) */

typedef std::function<void(std::string_view)> OnTextChanged;

// pass to SetColor() function to indicate this color should not change
#define NO_CHANGE (COLORREF)(-2) // -1 is taken by NO_COLOR in windows headers

/* Creation sequence:
- auto ctrl = new EditCtrl()
- set creation parameters
- ctrl.Create()
*/
struct EditCtrl : public WindowBase {
    // data that can be set directly

    str::Str cueText;
    OnTextChanged OnTextChanged;

    // set those via SetColors() to keep bgBrush in sync with bgCol
    HBRUSH bgBrush = nullptr;

    bool hasBorder = false;

    EditCtrl(HWND parent);
    ~EditCtrl();
    bool Create() override;
    SIZE GetIdealSize() override;
    LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp, bool& didHandle) override;
    LRESULT WndProcParent(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp, bool& didHandle) override;

    bool SetCueText(std::string_view);
};

ILayout* NewEditLayout(EditCtrl*);

bool IsEdit(Kind);
bool IsEdit(ILayout*);
