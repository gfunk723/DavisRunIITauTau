#include "TChain.h"
#include <iostream>
#include "TString.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <sstream>
#include <vector>
#include <algorithm>
#include <unistd.h>

bool useHTbinnedW = 1;

void fileLoad();

void setup_files_muTau_test();
void setup_files_eleTau_test();
void setup_files_eleMu_test();
void setup_files_TauTau_test();

void setup_files_muTau();
void setup_files_eleTau();
void setup_files_eleMu();
void setup_files_TauTau();

void setup_upTau_files_muTau();
void setup_downTau_files_muTau();

void setup_upTau_files_eleTau();
void setup_downTau_files_eleTau();

void setup_upTau_files_TauTau();
void setup_downTau_files_TauTau();

void testComplete();

void reset_files();

TChain * DATA = new TChain("TauCheck");

TChain * DY = new TChain("TauCheck");
TChain * W = new TChain("TauCheck");
TChain * VV = new TChain("TauCheck");
TChain * ZVV = new TChain("TauCheck");
TChain * EWK = new TChain("TauCheck");

TChain * TT = new TChain("TauCheck");

TChain * MZP600_MA0300  = new TChain("TauCheck");
TChain * MZP600_MA0400  = new TChain("TauCheck");

TChain * MZP800_MA0300  = new TChain("TauCheck");
TChain * MZP800_MA0400  = new TChain("TauCheck");
TChain * MZP800_MA0500  = new TChain("TauCheck");
TChain * MZP800_MA0600  = new TChain("TauCheck");

TChain * MZP1000_MA0300  = new TChain("TauCheck");
TChain * MZP1000_MA0400  = new TChain("TauCheck");
TChain * MZP1000_MA0500  = new TChain("TauCheck");
TChain * MZP1000_MA0600  = new TChain("TauCheck");
TChain * MZP1000_MA0700  = new TChain("TauCheck");
TChain * MZP1000_MA0800  = new TChain("TauCheck");

TChain * MZP1200_MA0300  = new TChain("TauCheck");
TChain * MZP1200_MA0400  = new TChain("TauCheck");
TChain * MZP1200_MA0500  = new TChain("TauCheck");
TChain * MZP1200_MA0600  = new TChain("TauCheck");
TChain * MZP1200_MA0700  = new TChain("TauCheck");
TChain * MZP1200_MA0800  = new TChain("TauCheck");

TChain * MZP1400_MA0300  = new TChain("TauCheck");
TChain * MZP1400_MA0400  = new TChain("TauCheck");
TChain * MZP1400_MA0500  = new TChain("TauCheck");
TChain * MZP1400_MA0600  = new TChain("TauCheck");
TChain * MZP1400_MA0700  = new TChain("TauCheck");
TChain * MZP1400_MA0800  = new TChain("TauCheck");

TChain * MZP1700_MA0300  = new TChain("TauCheck");
TChain * MZP1700_MA0400  = new TChain("TauCheck");
TChain * MZP1700_MA0500  = new TChain("TauCheck");
TChain * MZP1700_MA0600  = new TChain("TauCheck");
TChain * MZP1700_MA0700  = new TChain("TauCheck");
TChain * MZP1700_MA0800  = new TChain("TauCheck");

TChain * MZP2000_MA0300  = new TChain("TauCheck");
TChain * MZP2000_MA0400  = new TChain("TauCheck");
TChain * MZP2000_MA0500  = new TChain("TauCheck");
TChain * MZP2000_MA0600  = new TChain("TauCheck");
TChain * MZP2000_MA0700  = new TChain("TauCheck");
TChain * MZP2000_MA0800  = new TChain("TauCheck");

TChain * MZP2500_MA0300  = new TChain("TauCheck");
TChain * MZP2500_MA0400  = new TChain("TauCheck");
TChain * MZP2500_MA0500  = new TChain("TauCheck");
TChain * MZP2500_MA0600  = new TChain("TauCheck");
TChain * MZP2500_MA0700  = new TChain("TauCheck");
TChain * MZP2500_MA0800  = new TChain("TauCheck");


//BKG subgroups
//W
TChain * WJetsToLNu = new TChain("TauCheck");

TChain * W1JetsToLNu = new TChain("TauCheck");
TChain * W2JetsToLNu = new TChain("TauCheck");
TChain * W3JetsToLNu = new TChain("TauCheck");
TChain * W4JetsToLNu = new TChain("TauCheck");

TChain * WJetsToLNuHT100To200 = new TChain("TauCheck");
TChain * WJetsToLNuHT200To400 = new TChain("TauCheck");
TChain * WJetsToLNuHT400To600 = new TChain("TauCheck");
TChain * WJetsToLNuHT600To800 = new TChain("TauCheck");
TChain * WJetsToLNuHT800To1200 = new TChain("TauCheck");
TChain * WJetsToLNuHT1200To2500 = new TChain("TauCheck");
TChain * WJetsToLNuHT2500ToInf = new TChain("TauCheck");

//EWK
TChain * EWKWMinus2Jets = new TChain("TauCheck");
TChain * EWKWPlus2Jets = new TChain("TauCheck");
TChain * EWKZ2Jets_ZToLL = new TChain("TauCheck");
TChain * EWKZ2Jets_ZToNuNu = new TChain("TauCheck");

//DY
TChain * DYinc = new TChain("TauCheck");
TChain * DY1Jets = new TChain("TauCheck");
TChain * DY2Jets = new TChain("TauCheck");
TChain * DY3Jets = new TChain("TauCheck");
TChain * DY4Jets = new TChain("TauCheck");

//ZNuNu
TChain * ZJetsToNuNuHT100To200 = new TChain("TauCheck");
TChain * ZJetsToNuNuHT200To400 = new TChain("TauCheck");
TChain * ZJetsToNuNuHT400To600 = new TChain("TauCheck");
TChain * ZJetsToNuNuHT600To800 = new TChain("TauCheck");
TChain * ZJetsToNuNuHT800To1200 = new TChain("TauCheck");
TChain * ZJetsToNuNuHT1200To2500 = new TChain("TauCheck");
TChain * ZJetsToNuNuHT2500ToInf = new TChain("TauCheck");

//DY channels divided using bools
TChain * ZTT = new TChain("TauCheck");
TChain * ZJ = new TChain("TauCheck");
TChain * ZL = new TChain("TauCheck");

//TT subgroups
TChain * TTT = new TChain("TauCheck");
TChain * TTJ = new TChain("TauCheck");

//VV subgroups
TChain * VVT = new TChain("TauCheck");
TChain * VVJ = new TChain("TauCheck");

//SMH subgroups
//H
TChain * GluGluHTauTau = new TChain("TauCheck");
TChain * VBFHTauTau = new TChain("TauCheck");
//ZH
TChain * ZHTauTau = new TChain("TauCheck");

/*
TChain * WminusHToTauTau_M125 = new TChain("TauCheck");
TChain * WplusHToTauTau_M125 = new TChain("TauCheck");
TChain * ttHJetTT = new TChain("TauCheck");
TChain * GluGluHToWWTo2L2Nu = new TChain("TauCheck");
TChain * VBFHToWWTo2L2Nu = new TChain("TauCheck");
//WH Main
TChain * WHTauTau = new TChain("TauCheck");
*/

//VV

TChain * ST_tW_antitop_5f_inclusiveDecays = new TChain("TauCheck");
TChain * ST_tW_top_5f_inclusiveDecays = new TChain("TauCheck");
TChain * ST_t_channel_antitop_4f_leptonDecays = new TChain("TauCheck");
TChain * ST_t_channel_top_4f_leptonDecays = new TChain("TauCheck");
TChain * VVTo2L2Nu = new TChain("TauCheck");
TChain * WWTo1L1Nu2Q = new TChain("TauCheck");
TChain * WZTo1L1Nu2Q = new TChain("TauCheck");
TChain * WZTo1L3Nu = new TChain("TauCheck");
TChain * WZTo2L2Q = new TChain("TauCheck");
TChain * ZZTo2L2Q = new TChain("TauCheck");
TChain * ZZTo2Q2Nu = new TChain("TauCheck");
TChain * WWW = new TChain("TauCheck");
TChain * WWZ = new TChain("TauCheck");
TChain * WZZ = new TChain("TauCheck");
TChain * ZZZ = new TChain("TauCheck");

void fileLoad (TChain * CHAIN, TString PATH_TO_FILES, std::string FILE_NAME)
{

	FILE * CondorJobs;
	CondorJobs = popen("xrdfs root://cmseos.fnal.gov ls "+PATH_TO_FILES,"r");
	std::vector <std::string> condorVector;

	if ( CondorJobs != NULL )
    {
      char aline [ 10000 ]; 
      while ( fgets ( aline, sizeof aline, CondorJobs ) != NULL ) 
      {
         std::string astring(aline);
         astring.erase( std::remove( astring.begin(), astring.end(), '\n' ), astring.end() ) ;
         
         //Check for missing files
         
         std::string checkString = "/eos/uscms" + astring + "/" + FILE_NAME;
         //std::cout << checkString << std::endl;
         const char * checkChar = checkString.c_str();
         if (access(checkChar,F_OK) == -1) { std::cout << "NO FILE " << checkString << std::endl;}
         
         
         astring = "root://cmsxrootd.fnal.gov/" + astring + "/" + FILE_NAME;
         condorVector.push_back(astring);
      }
      fclose ( CondorJobs );
    }

	for(std::size_t i = 0; i<condorVector.size(); ++i)
	{
		CHAIN->Add(condorVector[i].c_str());
	}

}

//small sample setup for testing.

void setup_files_TauTau_test()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/Tau/", "davis_syncTree_BASELINE_TauTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_TauTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_files_TauTau_test TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";


}



void setup_files_eleTau_test()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleElectron/", "davis_syncTree_BASELINE_EleTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_EleTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_files_eleTau_test TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}


void setup_files_muTau_test()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleMuon/", "davis_syncTree_BASELINE_MuTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TEST/TEST/", "davis_syncTree_BASELINE_MuTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_files_muTau_test TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}

void setup_files_TauTau()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/Tau/", "davis_syncTree_BASELINE_TauTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_TauTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_files_TauTau TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";


}



void setup_files_eleTau()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleElectron/", "davis_syncTree_BASELINE_EleTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_EleTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_files_eleTau TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}


void setup_files_muTau()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleMuon/", "davis_syncTree_BASELINE_MuTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_MuTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_files_muTau TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}


void setup_upTau_files_TauTau()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/Tau/", "davis_syncTree_BASELINEupTau_TauTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_TauTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_upTau_files_TauTau TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}

void setup_downTau_files_TauTau()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/Tau/", "davis_syncTree_BASELINEdownTau_TauTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_TauTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_downTau_files_TauTau TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}

void setup_upTau_files_eleTau()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleElectron/", "davis_syncTree_BASELINEupTau_EleTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_EleTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_upTau_files_eleTau TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}


void setup_downTau_files_eleTau()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleElectron/", "davis_syncTree_BASELINEdownTau_EleTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_EleTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_downTau_files_eleTau TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}


void setup_upTau_files_muTau()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleMuon/", "davis_syncTree_BASELINEupTau_MuTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_MuTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_upTau_files_muTau TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}


void setup_downTau_files_muTau()
{
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleMuon/", "davis_syncTree_BASELINEdownTau_MuTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_MuTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    //Consolidate TChains to main BKG categories
    
    DY->Add(DYinc);
    DY->Add(DY1Jets);
    DY->Add(DY2Jets);
    DY->Add(DY3Jets);
    DY->Add(DY4Jets);
    DY->Add(EWKZ2Jets_ZToLL);
    DY->Add(EWKZ2Jets_ZToNuNu);
    
    EWK->Add(EWKWMinus2Jets);
    EWK->Add(EWKWPlus2Jets);

    ZTT = (TChain*) DY->CopyTree("IsZTT==1");
    ZJ = (TChain*) DY->CopyTree("IsZJ==1");
    ZL = (TChain*) DY->CopyTree("IsZL==1");
    
    TTT = (TChain*) TT->CopyTree("IsTTT==1");
    TTJ = (TChain*) TT->CopyTree("IsTTT==0");
    
    ZVV->Add(ZJetsToNuNuHT100To200);
    ZVV->Add(ZJetsToNuNuHT200To400);
    ZVV->Add(ZJetsToNuNuHT400To600);
    ZVV->Add(ZJetsToNuNuHT600To800);
    ZVV->Add(ZJetsToNuNuHT800To1200);
    ZVV->Add(ZJetsToNuNuHT1200To2500);
    ZVV->Add(ZJetsToNuNuHT2500ToInf);
    
    //Main W samples, choose 1 binning type
    if(useHTbinnedW==1)
    {
        W->Add(WJetsToLNu);
        W->Add(WJetsToLNuHT100To200);
        W->Add(WJetsToLNuHT200To400);
        W->Add(WJetsToLNuHT400To600);
        W->Add(WJetsToLNuHT600To800);
        W->Add(WJetsToLNuHT800To1200);
        W->Add(WJetsToLNuHT1200To2500);
        W->Add(WJetsToLNuHT2500ToInf);
    }
    else
    {
        W->Add(W1JetsToLNu);
        W->Add(W2JetsToLNu);
        W->Add(W3JetsToLNu);
        W->Add(W4JetsToLNu);
    }
    
    VV->Add(ST_t_channel_antitop_4f_leptonDecays);
    VV->Add(ST_t_channel_top_4f_leptonDecays);
    VV->Add(ST_tW_antitop_5f_inclusiveDecays);
    VV->Add(ST_tW_top_5f_inclusiveDecays);
    VV->Add(VVTo2L2Nu);
    VV->Add(WWTo1L1Nu2Q);
    VV->Add(WZTo1L1Nu2Q);
    VV->Add(WZTo1L3Nu);
    VV->Add(WZTo2L2Q);
    VV->Add(ZZTo2L2Q);
    VV->Add(ZZTo2Q2Nu);
    VV->Add(WWW);
    VV->Add(WWZ);
    VV->Add(WZZ);
    VV->Add(ZZZ);
    
    VVT = (TChain*) VV->CopyTree("IsZTT==1");
    VVJ = (TChain*) VV->CopyTree("IsZTT==0");
    
	std::cout<<" setup_downTau_files_muTau TChains set up .... \n";
    std::cout<<" DATA size "<<DATA->GetEntries()<<"\n";
    std::cout<<" TTT size "<<TTT->GetEntries()<<"\n";
    std::cout<<" TTJ size "<<TTJ->GetEntries()<<"\n";
    std::cout<<" W size "<<W->GetEntries()<<"\n";
    std::cout<<" ZTT size "<<ZTT->GetEntries()<<"\n";
    std::cout<<" ZL size "<<ZL->GetEntries()<<"\n";
    std::cout<<" ZJ size "<<ZJ->GetEntries()<<"\n";
    std::cout<<" EWK size" <<EWK->GetEntries()<<"\n";
    std::cout<<" ZVV size "<<ZVV->GetEntries()<<"\n";
    std::cout<<" VVT size "<<VVT->GetEntries()<<"\n";
    std::cout<<" VVJ size "<<VVJ->GetEntries()<<"\n";
    std::cout<<" ZHTauTau size "<<ZHTauTau->GetEntries()<<"\n";
    std::cout<<" GluGluHTauTau size "<<GluGluHTauTau->GetEntries()<<"\n";
    std::cout<<" VBFHTauTau size "<<VBFHTauTau->GetEntries()<<"\n";

}

void testComplete()
{

    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/Tau/", "davis_syncTree_BASELINE_TauTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_TauTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_TauTau.root");
  fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleElectron/", "davis_syncTree_BASELINE_EleTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_EleTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_EleTau.root");

    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleMuon/", "davis_syncTree_BASELINE_MuTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINE_MuTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINE_MuTau.root");
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/Tau/", "davis_syncTree_BASELINEupTau_TauTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_TauTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_TauTau.root");
    
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/Tau/", "davis_syncTree_BASELINEdownTau_TauTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_TauTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_TauTau.root");
    
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleElectron/", "davis_syncTree_BASELINEupTau_EleTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_EleTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_EleTau.root");
    
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleElectron/", "davis_syncTree_BASELINEdownTau_EleTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_EleTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_EleTau.root");
    
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleMuon/", "davis_syncTree_BASELINEupTau_MuTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEupTau_MuTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEupTau_MuTau.root");
    
    fileLoad(DATA, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DATA/SingleMuon/", "davis_syncTree_BASELINEdownTau_MuTau.root");

    fileLoad(GluGluHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_GluGluHTauTau/GluGluHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(VBFHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_VBFHTauTau/VBFHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZHTauTau, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_ZHTauTau/ZHToTauTau_M125_13TeV_powheg_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(TT, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/TT/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(ST_t_channel_antitop_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ST_t_channel_top_4f_leptonDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ST_tW_antitop_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ST_tW_top_5f_inclusiveDecays, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/", "davis_syncTree_BASELINEdownTau_MuTau.root");

    fileLoad(VVTo2L2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WWTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WZTo1L1Nu2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WZTo1L3Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZZTo2L2Q, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZZTo2Q2Nu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV//ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WZZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WWZ, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(WWW, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/VV/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    if(useHTbinnedW==1)
    {
        fileLoad(WJetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(WJetsToLNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    }
    else
    {
        fileLoad(W1JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(W2JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(W3JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        fileLoad(W4JetsToLNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/W/W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
        
    }
    
    fileLoad(DY1Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(DY2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(DY3Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(DY4Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(DYinc, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DY/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(ZJetsToNuNuHT100To200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-100To200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT200To400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-200To400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT400To600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-400To600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT600To800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-600To800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT800To1200, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT1200To2500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(ZJetsToNuNuHT2500ToInf, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/DYinv/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(EWKWMinus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(EWKWPlus2Jets, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(EWKZ2Jets_ZToLL, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(EWKZ2Jets_ZToNuNu, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/EWK/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP600_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP600_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP800_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP800_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP800_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP800_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP1000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP1200_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1200_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP1400_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1400_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP1700_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP1700_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP2000_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2000_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    
    fileLoad(MZP2500_MA0300, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0400, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0500, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0600, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0700, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    fileLoad(MZP2500_MA0800, "/store/user/gfunk/AprilProductionV1_8_0_26p1_V2/SIGNAL_MONO_HIGGS/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/", "davis_syncTree_BASELINEdownTau_MuTau.root");
    reset_files();

}


void reset_files()
{
    DATA->Reset();

    DY->Reset();
    W->Reset();
    VV->Reset();
    ZVV->Reset();
    EWK->Reset();

    TT->Reset();

    MZP600_MA0300->Reset();
    MZP600_MA0400->Reset();

    MZP800_MA0300->Reset();
    MZP800_MA0400->Reset();
    MZP800_MA0500->Reset();
    MZP800_MA0600->Reset();

    MZP1000_MA0300->Reset();
    MZP1000_MA0400->Reset();
    MZP1000_MA0500->Reset();
    MZP1000_MA0600->Reset();
    MZP1000_MA0700->Reset();
    MZP1000_MA0800->Reset();

    MZP1200_MA0300->Reset();
    MZP1200_MA0400->Reset();
    MZP1200_MA0500->Reset();
    MZP1200_MA0600->Reset();
    MZP1200_MA0700->Reset();
    MZP1200_MA0800->Reset();

    MZP1400_MA0300->Reset();
    MZP1400_MA0400->Reset();
    MZP1400_MA0500->Reset();
    MZP1400_MA0600->Reset();
    MZP1400_MA0700->Reset();
    MZP1400_MA0800->Reset();

    MZP1700_MA0300->Reset();
    MZP1700_MA0400->Reset();
    MZP1700_MA0500->Reset();
    MZP1700_MA0600->Reset();
    MZP1700_MA0700->Reset();
    MZP1700_MA0800->Reset();

    MZP2000_MA0300->Reset();
    MZP2000_MA0400->Reset();
    MZP2000_MA0500->Reset();
    MZP2000_MA0600->Reset();
    MZP2000_MA0700->Reset();
    MZP2000_MA0800->Reset();

    MZP2500_MA0300->Reset();
    MZP2500_MA0400->Reset();
    MZP2500_MA0500->Reset();
    MZP2500_MA0600->Reset();
    MZP2500_MA0700->Reset();
    MZP2500_MA0800->Reset();


    //BKG subgroups
    //W
    WJetsToLNu->Reset();

    W1JetsToLNu->Reset();
    W2JetsToLNu->Reset();
    W3JetsToLNu->Reset();
    W4JetsToLNu->Reset();

    WJetsToLNuHT100To200->Reset();
    WJetsToLNuHT200To400->Reset();
    WJetsToLNuHT400To600->Reset();
    WJetsToLNuHT600To800->Reset();
    WJetsToLNuHT800To1200->Reset();
    WJetsToLNuHT1200To2500->Reset();
    WJetsToLNuHT2500ToInf->Reset();

    //EWK
    EWKWMinus2Jets->Reset();
    EWKWPlus2Jets->Reset();
    EWKZ2Jets_ZToLL->Reset();
    EWKZ2Jets_ZToNuNu->Reset();

    //DY
    DYinc->Reset();
    DY1Jets->Reset();
    DY2Jets->Reset();
    DY3Jets->Reset();
    DY4Jets->Reset();

    //ZNuNu
    ZJetsToNuNuHT100To200->Reset();
    ZJetsToNuNuHT200To400->Reset();
    ZJetsToNuNuHT400To600->Reset();
    ZJetsToNuNuHT600To800->Reset();
    ZJetsToNuNuHT800To1200->Reset();
    ZJetsToNuNuHT1200To2500->Reset();
    ZJetsToNuNuHT2500ToInf->Reset();

    //DY channels divided using bools
    ZTT->Reset();
    ZJ->Reset();
    ZL->Reset();

    //TT subgroups
    TTT->Reset();
    TTJ->Reset();

    //SMH subgroups
    //H
    GluGluHTauTau->Reset();
    VBFHTauTau->Reset();
    //ZH
    ZHTauTau->Reset();

    /*
    WminusHToTauTau_M125->Reset();
    WplusHToTauTau_M125->Reset();
    ttHJetTT->Reset();
    GluGluHToWWTo2L2Nu->Reset();
    VBFHToWWTo2L2Nu->Reset();
    //WH Main
    WHTauTau->Reset();
    */

    //VV

    ST_tW_antitop_5f_inclusiveDecays->Reset();
    ST_tW_top_5f_inclusiveDecays->Reset();
    //ST_t_channel_antitop_4f_leptonDecays->Reset();
    //ST_t_channel_top_4f_leptonDecays->Reset();
    VVTo2L2Nu->Reset();
    WWTo1L1Nu2Q->Reset();
    WZTo1L1Nu2Q->Reset();
    WZTo1L3Nu->Reset();
    WZTo2L2Q->Reset();
    ZZTo2L2Q->Reset();
    WWW->Reset();
    WWZ->Reset();
    WZZ->Reset();
    ZZZ->Reset();
}
