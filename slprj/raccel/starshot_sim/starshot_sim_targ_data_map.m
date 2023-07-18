    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.starshot
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 42;
            section.data(42)  = dumData; %prealloc

                    ;% rtP.B0
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.G
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.M_Earth
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.R_Earth
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.q0
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Normalization_Bias
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 8;

                    ;% rtP.Constant_Value
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 9;

                    ;% rtP.Constant_Value_lprubj2kwa
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 10;

                    ;% rtP.Gain1_Gain
                    section.data(9).logicalSrcIdx = 9;
                    section.data(9).dtTransOffset = 11;

                    ;% rtP.Switch_Threshold
                    section.data(10).logicalSrcIdx = 10;
                    section.data(10).dtTransOffset = 12;

                    ;% rtP.Switch1_Threshold
                    section.data(11).logicalSrcIdx = 11;
                    section.data(11).dtTransOffset = 13;

                    ;% rtP.Gain2_Gain
                    section.data(12).logicalSrcIdx = 12;
                    section.data(12).dtTransOffset = 14;

                    ;% rtP.Gain_Gain
                    section.data(13).logicalSrcIdx = 13;
                    section.data(13).dtTransOffset = 15;

                    ;% rtP.Gain1_Gain_gxm1ihqq0u
                    section.data(14).logicalSrcIdx = 14;
                    section.data(14).dtTransOffset = 16;

                    ;% rtP.Gain2_Gain_dg5gskg1nm
                    section.data(15).logicalSrcIdx = 15;
                    section.data(15).dtTransOffset = 17;

                    ;% rtP.Gain1_Gain_fkz5w2tg5q
                    section.data(16).logicalSrcIdx = 16;
                    section.data(16).dtTransOffset = 18;

                    ;% rtP.MatrixGain_Gain
                    section.data(17).logicalSrcIdx = 17;
                    section.data(17).dtTransOffset = 19;

                    ;% rtP.Gain6_Gain
                    section.data(18).logicalSrcIdx = 18;
                    section.data(18).dtTransOffset = 28;

                    ;% rtP.Gain5_Gain
                    section.data(19).logicalSrcIdx = 19;
                    section.data(19).dtTransOffset = 29;

                    ;% rtP.Gain_Gain_cmgxch1a1l
                    section.data(20).logicalSrcIdx = 20;
                    section.data(20).dtTransOffset = 30;

                    ;% rtP.Gain1_Gain_mqjlhklks4
                    section.data(21).logicalSrcIdx = 21;
                    section.data(21).dtTransOffset = 31;

                    ;% rtP.Gain2_Gain_asqeevkcou
                    section.data(22).logicalSrcIdx = 22;
                    section.data(22).dtTransOffset = 32;

                    ;% rtP.Gain8_Gain
                    section.data(23).logicalSrcIdx = 23;
                    section.data(23).dtTransOffset = 33;

                    ;% rtP.Gain18_Gain
                    section.data(24).logicalSrcIdx = 24;
                    section.data(24).dtTransOffset = 34;

                    ;% rtP.Gain_Gain_ityqyfpnsc
                    section.data(25).logicalSrcIdx = 25;
                    section.data(25).dtTransOffset = 35;

                    ;% rtP.Gain1_Gain_eeykqncbdx
                    section.data(26).logicalSrcIdx = 26;
                    section.data(26).dtTransOffset = 36;

                    ;% rtP.Gain2_Gain_icunypzv3n
                    section.data(27).logicalSrcIdx = 27;
                    section.data(27).dtTransOffset = 37;

                    ;% rtP.Constant8_Value
                    section.data(28).logicalSrcIdx = 28;
                    section.data(28).dtTransOffset = 38;

                    ;% rtP.Identitymatrix_Value
                    section.data(29).logicalSrcIdx = 29;
                    section.data(29).dtTransOffset = 39;

                    ;% rtP.Constant3_Value
                    section.data(30).logicalSrcIdx = 30;
                    section.data(30).dtTransOffset = 48;

                    ;% rtP.Constant12_Value
                    section.data(31).logicalSrcIdx = 31;
                    section.data(31).dtTransOffset = 49;

                    ;% rtP.Constant3_Value_egvn5fzjrd
                    section.data(32).logicalSrcIdx = 32;
                    section.data(32).dtTransOffset = 50;

                    ;% rtP.e_z_Value
                    section.data(33).logicalSrcIdx = 33;
                    section.data(33).dtTransOffset = 51;

                    ;% rtP.Gain_Gain_p3pw120zm1
                    section.data(34).logicalSrcIdx = 34;
                    section.data(34).dtTransOffset = 54;

                    ;% rtP.Gain1_Gain_ees4kdgcpe
                    section.data(35).logicalSrcIdx = 35;
                    section.data(35).dtTransOffset = 55;

                    ;% rtP.Gain2_Gain_ed1hn35ith
                    section.data(36).logicalSrcIdx = 36;
                    section.data(36).dtTransOffset = 56;

                    ;% rtP.Constant3_Value_efe2zzothx
                    section.data(37).logicalSrcIdx = 37;
                    section.data(37).dtTransOffset = 57;

                    ;% rtP.Constant4_Value
                    section.data(38).logicalSrcIdx = 38;
                    section.data(38).dtTransOffset = 58;

                    ;% rtP.Constant10_Value
                    section.data(39).logicalSrcIdx = 39;
                    section.data(39).dtTransOffset = 59;

                    ;% rtP.Constant9_Value
                    section.data(40).logicalSrcIdx = 40;
                    section.data(40).dtTransOffset = 60;

                    ;% rtP.Constant3_Value_e341jwrb4z
                    section.data(41).logicalSrcIdx = 41;
                    section.data(41).dtTransOffset = 61;

                    ;% rtP.diag0_Value
                    section.data(42).logicalSrcIdx = 42;
                    section.data(42).dtTransOffset = 62;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.Switch_CurrentSetting
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 31;
            section.data(31)  = dumData; %prealloc

                    ;% rtB.dl3osgoi5y
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.eies2vobp0
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 4;

                    ;% rtB.dxtixaknsr
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 5;

                    ;% rtB.mh2cw3g21y
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% rtB.fiu0rfsd3a
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% rtB.mm0zbnflas
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% rtB.hofhehwala
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% rtB.ol5jg0fvut
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

                    ;% rtB.e3zxffjpma
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 13;

                    ;% rtB.fnusqcsyq4
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 16;

                    ;% rtB.femncko0cn
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 17;

                    ;% rtB.fpijzyolrb
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 20;

                    ;% rtB.mvhur03jr5
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 21;

                    ;% rtB.iuda0ybz3k
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 22;

                    ;% rtB.lr40woa5vs
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 23;

                    ;% rtB.otohkbp3bg
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 26;

                    ;% rtB.oytd10qstc
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 29;

                    ;% rtB.ao1jkqsvon
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 30;

                    ;% rtB.crqtrnf4td
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 31;

                    ;% rtB.frdvfzrycc
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 32;

                    ;% rtB.jpsplb3g3c
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 35;

                    ;% rtB.cek4ch2hyg
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 39;

                    ;% rtB.eeqjatg1dy
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 42;

                    ;% rtB.maipu1b40a
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 45;

                    ;% rtB.j2525zxruy
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 46;

                    ;% rtB.ghjrhwzi5l
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 47;

                    ;% rtB.i3p5tajv00
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 48;

                    ;% rtB.fpzp3jifvq
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 49;

                    ;% rtB.kokbtkt104
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 50;

                    ;% rtB.ip5sbal02i
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 51;

                    ;% rtB.dwztvfu4wu
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 52;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.ogos4ffr2t
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.gcvqyir2vi
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.ond4jhxyao
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.jg3q0pzg5o
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.ku5p2ni5nf
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.n1p1mm2auv
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.cycn54lzew
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% rtDW.nfnayvw4de
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% rtDW.edbxwvz1jp.LoggedData
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ow4wq5w5mm.AQHandles
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 3;

                    ;% rtDW.iqwe4azqcv.LoggedData
                    section.data(3).logicalSrcIdx = 10;
                    section.data(3).dtTransOffset = 4;

                    ;% rtDW.kmajz0sfwj.LoggedData
                    section.data(4).logicalSrcIdx = 11;
                    section.data(4).dtTransOffset = 7;

                    ;% rtDW.aaja0aysz0.AQHandles
                    section.data(5).logicalSrcIdx = 12;
                    section.data(5).dtTransOffset = 10;

                    ;% rtDW.mnlqyxwck2.LoggedData
                    section.data(6).logicalSrcIdx = 13;
                    section.data(6).dtTransOffset = 11;

                    ;% rtDW.hzbfcdgqjd.AQHandles
                    section.data(7).logicalSrcIdx = 14;
                    section.data(7).dtTransOffset = 12;

                    ;% rtDW.h30c31f5ui.LoggedData
                    section.data(8).logicalSrcIdx = 15;
                    section.data(8).dtTransOffset = 13;

                    ;% rtDW.nkyfajxfft.LoggedData
                    section.data(9).logicalSrcIdx = 16;
                    section.data(9).dtTransOffset = 16;

                    ;% rtDW.mi1tlyzydp.LoggedData
                    section.data(10).logicalSrcIdx = 17;
                    section.data(10).dtTransOffset = 19;

                    ;% rtDW.p2iiqtje1q.AQHandles
                    section.data(11).logicalSrcIdx = 18;
                    section.data(11).dtTransOffset = 23;

                    ;% rtDW.n4ujbk4ieg.AQHandles
                    section.data(12).logicalSrcIdx = 19;
                    section.data(12).dtTransOffset = 24;

                    ;% rtDW.fsavadaoi0.LoggedData
                    section.data(13).logicalSrcIdx = 20;
                    section.data(13).dtTransOffset = 25;

                    ;% rtDW.egik531awp.AQHandles
                    section.data(14).logicalSrcIdx = 21;
                    section.data(14).dtTransOffset = 28;

                    ;% rtDW.hnp1vq2ji2.AQHandles
                    section.data(15).logicalSrcIdx = 22;
                    section.data(15).dtTransOffset = 29;

                    ;% rtDW.c1v41m3tga.AQHandles
                    section.data(16).logicalSrcIdx = 23;
                    section.data(16).dtTransOffset = 30;

                    ;% rtDW.hs1apb1hkv.LoggedData
                    section.data(17).logicalSrcIdx = 24;
                    section.data(17).dtTransOffset = 31;

                    ;% rtDW.gsczcuj3aq.AQHandles
                    section.data(18).logicalSrcIdx = 25;
                    section.data(18).dtTransOffset = 34;

                    ;% rtDW.mgo3q33zw1.LoggedData
                    section.data(19).logicalSrcIdx = 26;
                    section.data(19).dtTransOffset = 35;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.c0pertugry
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.mjbfo4zbad
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.fzywhfz1mq
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% rtDW.nqpjy1fnao
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.b3cxmfme20
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.nvceavffbk
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.c5ymd2b5xe
                    section.data(4).logicalSrcIdx = 33;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.aoua3yfzjz
                    section.data(5).logicalSrcIdx = 34;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.onplct1sg4
                    section.data(6).logicalSrcIdx = 35;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.ayifxsfink
                    section.data(7).logicalSrcIdx = 36;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.o2dokb32i1
                    section.data(8).logicalSrcIdx = 37;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.cyspl0m50o
                    section.data(9).logicalSrcIdx = 38;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.kf3zmjwqmp
                    section.data(10).logicalSrcIdx = 39;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.eg24d5fcm1
                    section.data(11).logicalSrcIdx = 40;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.oea32fuhjg
                    section.data(12).logicalSrcIdx = 41;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.fuvtfvj1xu
                    section.data(13).logicalSrcIdx = 42;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.f4mltievmu
                    section.data(14).logicalSrcIdx = 43;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.nekjo4wvrj
                    section.data(15).logicalSrcIdx = 44;
                    section.data(15).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 450159784;
    targMap.checksum1 = 2054323638;
    targMap.checksum2 = 1979725367;
    targMap.checksum3 = 1508144400;

