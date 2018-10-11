#include "TMVAClassification_TMlpANN.h"
#include <cmath>

double TMVAClassification_TMlpANN::Value(int index,double in0,double in1,double in2,double in3,double in4,double in5,double in6) {
   input0 = (in0 - -0.0109192)/1.79286;
   input1 = (in1 - 0.040566)/1.76703;
   input2 = (in2 - -0.210447)/0.679382;
   input3 = (in3 - -0.217502)/0.671611;
   input4 = (in4 - -0.00405905)/0.503748;
   input5 = (in5 - 36034.9)/85588;
   input6 = (in6 - 34768.6)/79320.5;
   switch(index) {
     case 0:
         return neuron0x7fb1c8b0b640();
     default:
         return 0.;
   }
}

double TMVAClassification_TMlpANN::Value(int index, double* input) {
   input0 = (input[0] - -0.0109192)/1.79286;
   input1 = (input[1] - 0.040566)/1.76703;
   input2 = (input[2] - -0.210447)/0.679382;
   input3 = (input[3] - -0.217502)/0.671611;
   input4 = (input[4] - -0.00405905)/0.503748;
   input5 = (input[5] - 36034.9)/85588;
   input6 = (input[6] - 34768.6)/79320.5;
   switch(index) {
     case 0:
         return neuron0x7fb1c8b0b640();
     default:
         return 0.;
   }
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b06670() {
   return input0;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b068f0() {
   return input1;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b06bf0() {
   return input2;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b06ef0() {
   return input3;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b071f0() {
   return input4;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b074f0() {
   return input5;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b077f0() {
   return input6;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b07af0() {
   double input = -7.05816;
   input += synapse0x7fb1c8b06640();
   input += synapse0x7fb1c8b05c50();
   input += synapse0x7fb1c8b06420();
   input += synapse0x7fb1c8b07d70();
   input += synapse0x7fb1c8b07da0();
   input += synapse0x7fb1c8b07dd0();
   input += synapse0x7fb1c8b07e00();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b07af0() {
   double input = input0x7fb1c8b07af0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b07e30() {
   double input = -0.06015;
   input += synapse0x7fb1c8b08130();
   input += synapse0x7fb1c8b08160();
   input += synapse0x7fb1c8b08190();
   input += synapse0x7fb1c8b081c0();
   input += synapse0x7fb1c8b081f0();
   input += synapse0x7fb1c8b08220();
   input += synapse0x7fb1c8b08250();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b07e30() {
   double input = input0x7fb1c8b07e30();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b08280() {
   double input = 0.203662;
   input += synapse0x7fb1c8b08580();
   input += synapse0x7fb1c8b085b0();
   input += synapse0x7fb1c8b085e0();
   input += synapse0x7fb1c8b06450();
   input += synapse0x7fb1c8b08710();
   input += synapse0x7fb1c8b08740();
   input += synapse0x7fb1c8b08770();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b08280() {
   double input = input0x7fb1c8b08280();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b087a0() {
   double input = -3.56796;
   input += synapse0x7fb1c8b08a20();
   input += synapse0x7fb1c8b08a50();
   input += synapse0x7fb1c8b08a80();
   input += synapse0x7fb1c8b08ab0();
   input += synapse0x7fb1c8b08ae0();
   input += synapse0x7fb1c8b08b10();
   input += synapse0x7fb1c8b08b40();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b087a0() {
   double input = input0x7fb1c8b087a0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b08b70() {
   double input = -2.48206;
   input += synapse0x7fb1c8b08e70();
   input += synapse0x7fb1c8b08ea0();
   input += synapse0x7fb1c8b08ed0();
   input += synapse0x7fb1c8b08f00();
   input += synapse0x7fb1c8b08f30();
   input += synapse0x7fb1c8b08610();
   input += synapse0x7fb1c8b08640();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b08b70() {
   double input = input0x7fb1c8b08b70();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b09160() {
   double input = 1.26012;
   input += synapse0x7fb1c8b093e0();
   input += synapse0x7fb1c8b09410();
   input += synapse0x7fb1c8b09440();
   input += synapse0x7fb1c8b09470();
   input += synapse0x7fb1c8b094a0();
   input += synapse0x7fb1c8b094d0();
   input += synapse0x7fb1c8b09500();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b09160() {
   double input = input0x7fb1c8b09160();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b09530() {
   double input = -0.775985;
   input += synapse0x7fb1c8b09830();
   input += synapse0x7fb1c8b09860();
   input += synapse0x7fb1c8b09890();
   input += synapse0x7fb1c8b098c0();
   input += synapse0x7fb1c8b098f0();
   input += synapse0x7fb1c8b09920();
   input += synapse0x7fb1c8b09950();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b09530() {
   double input = input0x7fb1c8b09530();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b09980() {
   double input = 0.698416;
   input += synapse0x7fb1c8b09c80();
   input += synapse0x7fb1c8b09cb0();
   input += synapse0x7fb1c8b09ce0();
   input += synapse0x7fb1c8b09d10();
   input += synapse0x7fb1c8b09d40();
   input += synapse0x7fb1c8b09d70();
   input += synapse0x7fb1c8b09da0();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b09980() {
   double input = input0x7fb1c8b09980();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b09dd0() {
   double input = -4.53587;
   input += synapse0x7fb1c8b0a0d0();
   input += synapse0x7fb1c8b0a100();
   input += synapse0x7fb1c8b0a130();
   input += synapse0x7fb1c8b0a160();
   input += synapse0x7fb1c8b0a190();
   input += synapse0x7fb1c8b0a1c0();
   input += synapse0x7fb1c8b0a1f0();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b09dd0() {
   double input = input0x7fb1c8b09dd0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b0a220() {
   double input = 0.628334;
   input += synapse0x7fb1c8b0a620();
   input += synapse0x7fb1c8b0a650();
   input += synapse0x7fb1c8b08f60();
   input += synapse0x7fb1c8b08f90();
   input += synapse0x7fb1c8b08fc0();
   input += synapse0x7fb1c8b08ff0();
   input += synapse0x7fb1c8b09020();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b0a220() {
   double input = input0x7fb1c8b0a220();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b0a680() {
   double input = -6.03781;
   input += synapse0x7fb1c8b0a800();
   input += synapse0x7fb1c8b0a830();
   input += synapse0x7fb1c8b0a860();
   input += synapse0x7fb1c8b0a890();
   input += synapse0x7fb1c8b0a8c0();
   input += synapse0x7fb1c8b0a8f0();
   input += synapse0x7fb1c8b0a920();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b0a680() {
   double input = input0x7fb1c8b0a680();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b0a950() {
   double input = 0.319811;
   input += synapse0x7fb1c8b0ac50();
   input += synapse0x7fb1c8b0ac80();
   input += synapse0x7fb1c8b0acb0();
   input += synapse0x7fb1c8b0ace0();
   input += synapse0x7fb1c8b0ad10();
   input += synapse0x7fb1c8b0ad40();
   input += synapse0x7fb1c8b0ad70();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b0a950() {
   double input = input0x7fb1c8b0a950();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b0ada0() {
   double input = -0.419552;
   input += synapse0x7fb1c8b0b0a0();
   input += synapse0x7fb1c8b0b0d0();
   input += synapse0x7fb1c8b0b100();
   input += synapse0x7fb1c8b0b130();
   input += synapse0x7fb1c8b0b160();
   input += synapse0x7fb1c8b0b190();
   input += synapse0x7fb1c8b0b1c0();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b0ada0() {
   double input = input0x7fb1c8b0ada0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b0b1f0() {
   double input = 0.493662;
   input += synapse0x7fb1c8b0b4f0();
   input += synapse0x7fb1c8b0b520();
   input += synapse0x7fb1c8b0b550();
   input += synapse0x7fb1c8b0b580();
   input += synapse0x7fb1c8b0b5b0();
   input += synapse0x7fb1c8b0b5e0();
   input += synapse0x7fb1c8b0b610();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b0b1f0() {
   double input = input0x7fb1c8b0b1f0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double TMVAClassification_TMlpANN::input0x7fb1c8b0b640() {
   double input = -4.62794;
   input += synapse0x7fb1c8b06580();
   input += synapse0x7fb1c8b0b840();
   input += synapse0x7fb1c8b0b870();
   input += synapse0x7fb1c8b0b8a0();
   input += synapse0x7fb1c8b0b8d0();
   input += synapse0x7fb1c8b0b900();
   input += synapse0x7fb1c8b0b930();
   return input;
}

double TMVAClassification_TMlpANN::neuron0x7fb1c8b0b640() {
   double input = input0x7fb1c8b0b640();
   return (input * 1)+0;
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b06640() {
   return (neuron0x7fb1c8b06670()*-0.0683858);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b05c50() {
   return (neuron0x7fb1c8b068f0()*-0.0306414);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b06420() {
   return (neuron0x7fb1c8b06bf0()*-1.15895);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b07d70() {
   return (neuron0x7fb1c8b06ef0()*-0.879203);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b07da0() {
   return (neuron0x7fb1c8b071f0()*-0.00490017);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b07dd0() {
   return (neuron0x7fb1c8b074f0()*-3.66046);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b07e00() {
   return (neuron0x7fb1c8b077f0()*-7.15254);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08130() {
   return (neuron0x7fb1c8b06670()*0.350286);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08160() {
   return (neuron0x7fb1c8b068f0()*-0.168487);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08190() {
   return (neuron0x7fb1c8b06bf0()*-4.74432);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b081c0() {
   return (neuron0x7fb1c8b06ef0()*-3.91559);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b081f0() {
   return (neuron0x7fb1c8b071f0()*-0.0344672);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08220() {
   return (neuron0x7fb1c8b074f0()*1.08334);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08250() {
   return (neuron0x7fb1c8b077f0()*0.195579);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08580() {
   return (neuron0x7fb1c8b06670()*2.07552);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b085b0() {
   return (neuron0x7fb1c8b068f0()*0.199072);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b085e0() {
   return (neuron0x7fb1c8b06bf0()*7.94508);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b06450() {
   return (neuron0x7fb1c8b06ef0()*5.61555);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08710() {
   return (neuron0x7fb1c8b071f0()*0.124736);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08740() {
   return (neuron0x7fb1c8b074f0()*-10.1466);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08770() {
   return (neuron0x7fb1c8b077f0()*0.321194);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08a20() {
   return (neuron0x7fb1c8b06670()*-0.0626205);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08a50() {
   return (neuron0x7fb1c8b068f0()*-0.00243437);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08a80() {
   return (neuron0x7fb1c8b06bf0()*7.85604);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08ab0() {
   return (neuron0x7fb1c8b06ef0()*7.85218);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08ae0() {
   return (neuron0x7fb1c8b071f0()*0.0585308);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08b10() {
   return (neuron0x7fb1c8b074f0()*-0.543616);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08b40() {
   return (neuron0x7fb1c8b077f0()*-0.205808);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08e70() {
   return (neuron0x7fb1c8b06670()*-0.115486);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08ea0() {
   return (neuron0x7fb1c8b068f0()*-0.0705268);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08ed0() {
   return (neuron0x7fb1c8b06bf0()*-3.02523);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08f00() {
   return (neuron0x7fb1c8b06ef0()*-2.72727);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08f30() {
   return (neuron0x7fb1c8b071f0()*-0.00425554);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08610() {
   return (neuron0x7fb1c8b074f0()*5.28979);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08640() {
   return (neuron0x7fb1c8b077f0()*0.747442);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b093e0() {
   return (neuron0x7fb1c8b06670()*0.285265);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09410() {
   return (neuron0x7fb1c8b068f0()*-0.135162);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09440() {
   return (neuron0x7fb1c8b06bf0()*-4.03486);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09470() {
   return (neuron0x7fb1c8b06ef0()*-3.32738);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b094a0() {
   return (neuron0x7fb1c8b071f0()*-0.0328206);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b094d0() {
   return (neuron0x7fb1c8b074f0()*2.96682);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09500() {
   return (neuron0x7fb1c8b077f0()*-1.82665);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09830() {
   return (neuron0x7fb1c8b06670()*-0.279262);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09860() {
   return (neuron0x7fb1c8b068f0()*0.207188);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09890() {
   return (neuron0x7fb1c8b06bf0()*4.76279);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b098c0() {
   return (neuron0x7fb1c8b06ef0()*3.43948);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b098f0() {
   return (neuron0x7fb1c8b071f0()*0.0628072);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09920() {
   return (neuron0x7fb1c8b074f0()*-0.28891);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09950() {
   return (neuron0x7fb1c8b077f0()*-0.807792);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09c80() {
   return (neuron0x7fb1c8b07af0()*6.38667);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09cb0() {
   return (neuron0x7fb1c8b07e30()*3.77009);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09ce0() {
   return (neuron0x7fb1c8b08280()*2.14229);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09d10() {
   return (neuron0x7fb1c8b087a0()*7.58381);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09d40() {
   return (neuron0x7fb1c8b08b70()*3.63962);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09d70() {
   return (neuron0x7fb1c8b09160()*-5.60421);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09da0() {
   return (neuron0x7fb1c8b09530()*-3.80923);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a0d0() {
   return (neuron0x7fb1c8b07af0()*-3.86634);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a100() {
   return (neuron0x7fb1c8b07e30()*-2.49419);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a130() {
   return (neuron0x7fb1c8b08280()*-0.26322);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a160() {
   return (neuron0x7fb1c8b087a0()*7.93322);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a190() {
   return (neuron0x7fb1c8b08b70()*3.06025);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a1c0() {
   return (neuron0x7fb1c8b09160()*7.76453);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a1f0() {
   return (neuron0x7fb1c8b09530()*1.96777);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a620() {
   return (neuron0x7fb1c8b07af0()*15.8913);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a650() {
   return (neuron0x7fb1c8b07e30()*-12.1917);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08f60() {
   return (neuron0x7fb1c8b08280()*0.357097);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08f90() {
   return (neuron0x7fb1c8b087a0()*5.94501);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08fc0() {
   return (neuron0x7fb1c8b08b70()*-7.58203);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b08ff0() {
   return (neuron0x7fb1c8b09160()*10.2527);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b09020() {
   return (neuron0x7fb1c8b09530()*-9.19535);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a800() {
   return (neuron0x7fb1c8b07af0()*3.03342);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a830() {
   return (neuron0x7fb1c8b07e30()*-1.51805);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a860() {
   return (neuron0x7fb1c8b08280()*0.0436796);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a890() {
   return (neuron0x7fb1c8b087a0()*9.34195);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a8c0() {
   return (neuron0x7fb1c8b08b70()*3.08886);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a8f0() {
   return (neuron0x7fb1c8b09160()*8.84899);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0a920() {
   return (neuron0x7fb1c8b09530()*2.3887);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0ac50() {
   return (neuron0x7fb1c8b07af0()*16.4023);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0ac80() {
   return (neuron0x7fb1c8b07e30()*-11.0424);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0acb0() {
   return (neuron0x7fb1c8b08280()*0.533108);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0ace0() {
   return (neuron0x7fb1c8b087a0()*5.93112);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0ad10() {
   return (neuron0x7fb1c8b08b70()*-7.37968);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0ad40() {
   return (neuron0x7fb1c8b09160()*9.95841);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0ad70() {
   return (neuron0x7fb1c8b09530()*-8.99411);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b0a0() {
   return (neuron0x7fb1c8b07af0()*-0.234033);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b0d0() {
   return (neuron0x7fb1c8b07e30()*-2.94341);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b100() {
   return (neuron0x7fb1c8b08280()*-2.16268);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b130() {
   return (neuron0x7fb1c8b087a0()*-6.16585);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b160() {
   return (neuron0x7fb1c8b08b70()*-3.41476);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b190() {
   return (neuron0x7fb1c8b09160()*4.29184);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b1c0() {
   return (neuron0x7fb1c8b09530()*2.54689);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b4f0() {
   return (neuron0x7fb1c8b07af0()*4.71844);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b520() {
   return (neuron0x7fb1c8b07e30()*-3.12486);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b550() {
   return (neuron0x7fb1c8b08280()*-2.46587);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b580() {
   return (neuron0x7fb1c8b087a0()*-7.62906);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b5b0() {
   return (neuron0x7fb1c8b08b70()*-3.58467);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b5e0() {
   return (neuron0x7fb1c8b09160()*3.51415);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b610() {
   return (neuron0x7fb1c8b09530()*1.81186);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b06580() {
   return (neuron0x7fb1c8b09980()*4.64136);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b840() {
   return (neuron0x7fb1c8b09dd0()*8.52367);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b870() {
   return (neuron0x7fb1c8b0a220()*-13.7068);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b8a0() {
   return (neuron0x7fb1c8b0a680()*-8.53278);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b8d0() {
   return (neuron0x7fb1c8b0a950()*13.7969);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b900() {
   return (neuron0x7fb1c8b0ada0()*10.48);
}

double TMVAClassification_TMlpANN::synapse0x7fb1c8b0b930() {
   return (neuron0x7fb1c8b0b1f0()*-4.8208);
}

