/*double GetZmmSF(float jets, float mj, float pthi, float syst){
        double aweight=1.0;
        if (syst==0){
            if (jets==2 && mj>300){//VBF
                if (mj>=300 && mj<700) aweight=1.06;
                if (mj>=700 && mj<1100) aweight=0.98;
                if (mj>=1100 && mj<1500) aweight=0.95;
                if (mj>=1500) aweight=0.95;
           }
        }
        if (syst==1){
            if (jets==2 && mj>300){//VBF
                if (mj>=300 && mj<700) aweight=1.12;
                if (mj>=700 && mj<1100) aweight=0.96;
                if (mj>=1100 && mj<1500) aweight=0.90;
                if (mj>=1500) aweight=0.90;
           }
        }
        return aweight;
}*/


double GetZmmSF(float jets, float mj, float pthi, float taupt, float syst){
	double aweight=1.0;
        if (syst==0){
            if (jets>=2 && mj>300 && taupt>40 && pthi>50){//VBF
                if (mj>=300 && mj<700) aweight=1.070;
                if (mj>=700 && mj<1100) aweight=1.090;
                if (mj>=1100 && mj<1500) aweight=1.055;
                if (mj>=1500) aweight=1.015;
           }
        }
        if (syst==1){
            if (jets>=2 && mj>300 && taupt>40 && pthi>50){//VBF
                if (mj>=300 && mj<700) aweight=1.14;
                if (mj>=700 && mj<1100) aweight=1.18;
                if (mj>=1100 && mj<1500) aweight=1.11;
                if (mj>=1500) aweight=1.030;
           }
        }
        return aweight;
}
