// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "Vsigdelay__pch.h"
#include "Vsigdelay___024root.h"

void Vsigdelay___024root___eval_act(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsigdelay___024root___nba_sequent__TOP__0(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ __Vdly__sigdelay__DOT__addr;
    __Vdly__sigdelay__DOT__addr = 0;
    SData/*8:0*/ __Vdlyvdim0__sigdelay__DOT__RAM__DOT__ram_array__v0;
    __Vdlyvdim0__sigdelay__DOT__RAM__DOT__ram_array__v0 = 0;
    CData/*7:0*/ __Vdlyvval__sigdelay__DOT__RAM__DOT__ram_array__v0;
    __Vdlyvval__sigdelay__DOT__RAM__DOT__ram_array__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sigdelay__DOT__RAM__DOT__ram_array__v0;
    __Vdlyvset__sigdelay__DOT__RAM__DOT__ram_array__v0 = 0;
    // Body
    __Vdly__sigdelay__DOT__addr = vlSelf->sigdelay__DOT__addr;
    __Vdlyvset__sigdelay__DOT__RAM__DOT__ram_array__v0 = 0U;
    __Vdly__sigdelay__DOT__addr = ((IData)(vlSelf->rst)
                                    ? 0U : (0x1ffU 
                                            & ((IData)(1U) 
                                               + (IData)(vlSelf->sigdelay__DOT__addr))));
    if (vlSelf->wr) {
        __Vdlyvval__sigdelay__DOT__RAM__DOT__ram_array__v0 
            = vlSelf->mic_signal;
        __Vdlyvset__sigdelay__DOT__RAM__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__sigdelay__DOT__RAM__DOT__ram_array__v0 
            = vlSelf->sigdelay__DOT__addr;
    }
    if (vlSelf->rd) {
        vlSelf->delayed_signal = vlSelf->sigdelay__DOT__RAM__DOT__ram_array
            [(0x1ffU & ((IData)(vlSelf->sigdelay__DOT__addr) 
                        - (IData)(vlSelf->offset)))];
    }
    if (__Vdlyvset__sigdelay__DOT__RAM__DOT__ram_array__v0) {
        vlSelf->sigdelay__DOT__RAM__DOT__ram_array[__Vdlyvdim0__sigdelay__DOT__RAM__DOT__ram_array__v0] 
            = __Vdlyvval__sigdelay__DOT__RAM__DOT__ram_array__v0;
    }
    vlSelf->sigdelay__DOT__addr = __Vdly__sigdelay__DOT__addr;
}

void Vsigdelay___024root___eval_nba(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsigdelay___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vsigdelay___024root___eval_triggers__act(Vsigdelay___024root* vlSelf);

bool Vsigdelay___024root___eval_phase__act(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsigdelay___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsigdelay___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsigdelay___024root___eval_phase__nba(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsigdelay___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__nba(Vsigdelay___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__act(Vsigdelay___024root* vlSelf);
#endif  // VL_DEBUG

void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsigdelay___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sigdelay.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsigdelay___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sigdelay.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsigdelay___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsigdelay___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->wr & 0xfeU))) {
        Verilated::overWidthError("wr");}
    if (VL_UNLIKELY((vlSelf->rd & 0xfeU))) {
        Verilated::overWidthError("rd");}
    if (VL_UNLIKELY((vlSelf->offset & 0xfe00U))) {
        Verilated::overWidthError("offset");}
}
#endif  // VL_DEBUG
