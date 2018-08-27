#ifndef TEST_FEED_CONTROL_H
#define TEST_FEED_CONTROL_H

#include "systemc.h"

SC_MODULE(test_feed_control){

    uint pos;
    sc_out<sc_bv<7>> out_opcode;
    sc_in<bool> call_in;

    bool flag_setup_protect = true;

    uint test_inst[68] = {
              0xfc010113,
              0x02813c23,
              0x04010413,
              0x00010793,
              0x00078513,
              0x00a00793,
              0xfef42023,
              0x01400793,
              0xfef42223,
              0xfe442783,
              0xfff78793,
              0xfef43423,
              0xfe442783,
              0x00279693,
              0xfe042783,
              0xfff78793,
              0xfcf43823,
              0xfe442703,
              0xfe042783,
              0x02f707b3,
              0x00279793,
              0x00378793,
              0x00f78793,
              0x0047d793,
              0x00479793,
              0x40f10133,
              0x00010793,
              0x00378793,
              0x0027d793,
              0x00279793,
              0xfcf43423,
              0xfc042c23,
              0x0600006f,
              0xfc042e23,
              0x0380006f,
              0x0026d793,
              0xfc843703,
              0xfdc42603,
              0xfd842583,
              0x02f587b3,
              0x00f607b3,
              0x00279793,
              0x00f707b3,
              0x0007a783,
              0xfcf42223,
              0xfdc42783,
              0x0017879b,
              0xfcf42e23,
              0xfdc42703,
              0xfe442783,
              0x0007071b,
              0x0007879b,
              0xfaf74ee3,
              0xfd842783,
              0x0017879b,
              0xfcf42c23,
              0xfd842703,
              0xfe042783,
              0x0007071b,
              0x0007879b,
              0xf8f74ae3,
              0x00000793,
              0x00050113,
              0x00078513,
              0xfc040113,
              0x03813403,
              0x04010113,
              0x00008067};

    SC_CTOR(test_feed_control){

        pos = 0;

        SC_METHOD(feed){
        sensitive << call_in;
        }

    }

    void feed();

};


#endif // TEST_FEED_CONTROL_H
