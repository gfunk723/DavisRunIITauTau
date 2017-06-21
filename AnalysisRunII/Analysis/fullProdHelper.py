
# -*- coding: utf-8 -*-
#!/usr/local/bin/python
import subprocess
import os
import sys
import math
import time

def getDirList(inDir):
    tempfile = open('tempFile.txt','a+')
    cmd = 'find ' + inDir + ' -mindepth 2 -not -name *.root'
    print cmd
    process = subprocess.Popen(cmd.split(), shell=False, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    tempfile.write(process.communicate()[0])
    outDirList = []
    tempfile.close()
    with open('tempFile.txt','r') as readfile:
        outDirList = readfile.readlines()
    readfile.close()
    os.remove('tempFile.txt')
    outDirList = [char.replace("\n","/") for char in outDirList]
    outDirList = [char.replace("/eos/uscms/","/") for char in outDirList]
    for char in outDirList:
        if 'No such file or directory' in char:
            sys.exit('Abort. File not found.')
    return outDirList

filesPerJob = 5
topDirName = "/eos/uscms/store/user/gfunk/MayProductionV1_8_0_26p1_V11/"

subprocess.call('make clean', shell = True)
subprocess.call('make', shell = True)

storageDirNames = topDirName.split("/")
if storageDirNames[len(storageDirNames) - 1] == '':
   storageDirName = storageDirNames[len(storageDirNames) - 2] + '_fileLists'
else:
   storageDirName = storageDirNames[len(storageDirNames) - 1] + '_fileLists'
subprocess.call('mkdir ' + storageDirName, shell = True)

bkgDirLists = [
            ["WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/shalhout/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_GenBosonFixTry1/"),"W"],
            ["WJetsToLNu_HT-70To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/shalhout/WJetsToLNu_HT-70To100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_GenBosonFixTry1/"),"W"],
            ["WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/shalhout/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_GenBosonFixTry1/"),"W"],
            ["WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/shalhout/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_GenBosonFixTry1/"),"W"],
            ["WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/shalhout/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_GenBosonFixTry1/"),"W"],
            ["WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/shalhout/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_GenBosonFixTry1/"),"W"],
            ["WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/shalhout/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_GenBosonFixTry1/"),"W"],
            ["WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/shalhout/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_GenBosonFixTry1/"),"W"],
            ["WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/shalhout/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_GenBosonFixTry1/"),"W"],
            ["ZJetsToNuNu_HT-100To200_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZJetsToNuNu_HT-100To200_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"DYinv"],
            ["ZJetsToNuNu_HT-200To400_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZJetsToNuNu_HT-200To400_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"DYinv"],
            ["ZJetsToNuNu_HT-400To600_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZJetsToNuNu_HT-400To600_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"DYinv"],
            ["ZJetsToNuNu_HT-600To800_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZJetsToNuNu_HT-600To800_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"DYinv"],
            ["ZJetsToNuNu_HT-800To1200_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZJetsToNuNu_HT-800To1200_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"DYinv"],
            ["ZJetsToNuNu_HT-1200To2500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZJetsToNuNu_HT-1200To2500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"DYinv"],
            ["ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"DYinv"],
            ["GluGluHToTauTau_M125_13TeV_powheg_pythia8",getDirList("/eos/uscms/store/user/shalhout/GluGluHToTauTau_M125_13TeV_powheg_pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_GluGluHTauTau"],
            ["VBFHToTauTau_M125_13TeV_powheg_pythia8",getDirList("/eos/uscms/store/user/shalhout/VBFHToTauTau_M125_13TeV_powheg_pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_VBFHTauTau"],
            ["ZHToTauTau_M125_13TeV_powheg_pythia8",getDirList("/eos/uscms/store/user/shalhout/ZHToTauTau_M125_13TeV_powheg_pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_ZHTauTau"],
            ["VBFHToWWTo2L2Nu_M125_13TeV_powheg_JHUgen_pythia8",getDirList("/eos/uscms/store/user/shalhout/VBFHToWWTo2L2Nu_M125_13TeV_powheg_JHUgen_pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_HWW2L2Nu"],
            ["GluGluHToWWTo2L2Nu_M125_13TeV_powheg_JHUgen_pythia8",getDirList("/eos/uscms/store/user/shalhout/GluGluHToWWTo2L2Nu_M125_13TeV_powheg_JHUgen_pythia8/Moriond17_GenBosonFixTry1/"),"SIGNAL_HWW2L2Nu"],
            ["SingleElectron",getDirList("/eos/uscms/store/user/shalhout/SingleElectron/Moriond17_BTAGFIXtry1Run2016B-03Feb2017_ver2-v2") + getDirList("/eos/uscms/store/user/shalhout/SingleElectron/Moriond17_BTAGFIXtry1Run2016C-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleElectron/Moriond17_BTAGFIXtry1Run2016D-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleElectron/Moriond17_BTAGFIXtry1Run2016E-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleElectron/Moriond17_BTAGFIXtry1Run2016F-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleElectron/Moriond17_BTAGFIXtry1Run2016G-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleElectron/Moriond17_BTAGFIXtry1Run2016G-03Feb2017-v1RECOVER") + getDirList("/eos/uscms/store/user/shalhout/SingleElectron/Moriond17_BTAGFIXtry1Run2016H-03Feb2017_ver2-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleElectron/Moriond17_BTAGFIXtry1Run2016H-03Feb2017_ver3-v1"),"DATA"],
            ["SingleMuon",getDirList("/eos/uscms/store/user/shalhout/SingleMuon/Moriond17_BTAGFIXtry1Run2016B-03Feb2017_ver2-v2") + getDirList("/eos/uscms/store/user/shalhout/SingleMuon/Moriond17_BTAGFIXtry1Run2016C-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleMuon/Moriond17_BTAGFIXtry1Run2016D-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleMuon/Moriond17_BTAGFIXtry1Run2016E-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleMuon/Moriond17_BTAGFIXtry1Run2016F-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleMuon/Moriond17_BTAGFIXtry1Run2016G-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleMuon/Moriond17_BTAGFIXtry1Run2016H-03Feb2017_ver2-v1") + getDirList("/eos/uscms/store/user/shalhout/SingleMuon/Moriond17_BTAGFIXtry1Run2016H-03Feb2017_ver3-v1"),"DATA"],
            ["Tau",getDirList("/eos/uscms/store/user/shalhout/Tau/Moriond17_BTAGFIXtry1Run2016B-03Feb2017_ver2-v2") + getDirList("/eos/uscms/store/user/shalhout/Tau/Moriond17_BTAGFIXtry2Run2016C-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/Tau/Moriond17_BTAGFIXtry1Run2016D-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/Tau/Moriond17_BTAGFIXtry1Run2016E-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/Tau/Moriond17_BTAGFIXtry1Run2016F-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/Tau/Moriond17_BTAGFIXtry1Run2016G-03Feb2017-v1") + getDirList("/eos/uscms/store/user/shalhout/Tau/Moriond17_BTAGFIXtry1Run2016H-03Feb2017_ver2-v1") + getDirList("/eos/uscms/store/user/shalhout/Tau/Moriond17_BTAGFIXtry1Run2016H-03Feb2017_ver3-v1"),"DATA"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-600_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-400_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-800_MA0-300_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-400_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-600_MA0-300_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-800_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-700_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-600_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-400_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2500_MA0-300_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-800_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-700_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-600_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-400_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-2000_MA0-300_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-800_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-700_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-600_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-400_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1700_MA0-300_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-800_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-700_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-600_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-400_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1400_MA0-300_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-800_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-700_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-600_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-400_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1200_MA0-300_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-800_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-700_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-600_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-400_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/shalhout/ZprimeToA0hToA0chichihtautau_2HDM_MZp-1000_MA0-300_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-995_MChi-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-995_MChi-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-95_MChi-50_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-95_MChi-50_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-50_MChi-50_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-50_MChi-50_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-50_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-50_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-50_MChi-10_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-50_MChi-10_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-500_MChi-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-500_MChi-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-500_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-500_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-500_MChi-150_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-500_MChi-150_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-300_MChi-50_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-300_MChi-50_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-300_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-300_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-295_MChi-150_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-295_MChi-150_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-20_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-20_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-200_MChi-50_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-200_MChi-50_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-200_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-200_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-200_MChi-150_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-200_MChi-150_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-2000_MChi-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-2000_MChi-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-2000_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-2000_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-1995_MChi-1000_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-1995_MChi-1000_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-15_MChi-10_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-15_MChi-10_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10_MChi-50_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10_MChi-50_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10_MChi-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10_MChi-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10_MChi-150_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10_MChi-150_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10_MChi-10_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10_MChi-10_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10_MChi-1000_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10_MChi-1000_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-100_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-100_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-100_MChi-10_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-100_MChi-10_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-1000_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-1000_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-1000_MChi-150_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-1000_MChi-150_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-1000_MChi-1000_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-1000_MChi-1000_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10000_MChi-50_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10000_MChi-50_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10000_MChi-500_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10000_MChi-500_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10000_MChi-1_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10000_MChi-1_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10000_MChi-150_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10000_MChi-150_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10000_MChi-10_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10000_MChi-10_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["MonoHtautau_ZpBaryonic_MZp-10000_MChi-1000_13TeV-madgraph",getDirList("/eos/uscms/store/user/shalhout/MonoHtautau_ZpBaryonic_MZp-10000_MChi-1000_13TeV-madgraph/Moriond17_BTAGFIXtry1/"),"SIGNAL_MONO_HIGGS"],
            ["EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/gfunk/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/")+getDirList("/eos/uscms/store/user/shalhout/EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/Moriond17_GenBosonFixTry1/"),"EWK"],
            ["EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/gfunk/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/") + getDirList("/eos/uscms/store/user/shalhout/EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8/Moriond17_GenBosonFixTry1/"),"EWK"],
            ["EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/gfunk/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/") + getDirList("/eos/uscms/store/user/shalhout/EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8/Moriond17_GenBosonFixTry1/"),"EWK"],
            ["EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8",getDirList("/eos/uscms/store/user/gfunk/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/Moriond17_BTAGFIXtry1/") + getDirList("/eos/uscms/store/user/shalhout/EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8/Moriond17_GenBosonFixTry1/"),"EWK"],
            ["DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/gfunk/DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_BTAGFIXtry1/"),"DY"],
            ["DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/gfunk/DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_BTAGFIXtry1/"),"DY"],
            ["DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/gfunk/DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_BTAGFIXtry1/"),"DY"],
            ["DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/gfunk/DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_BTAGFIXtry1/"),"DY"],
            ["DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8",getDirList("/eos/uscms/store/user/gfunk/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/Moriond17_BTAGFIXtry2/"),"DY"],
            ["TT_TuneCUETP8M2T4_13TeV-powheg-pythia8",getDirList("/eos/uscms/store/user/gfunk/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/Moriond17_BTAGFIXtry1/"),"TT"],
            ["WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8",getDirList("/eos/uscms/store/user/gfunk/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8",getDirList("/eos/uscms/store/user/gfunk/ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8",getDirList("/eos/uscms/store/user/gfunk/ZZTo2Q2Nu_13TeV_amcatnloFXFX_madspin_pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["ZZTo4L_13TeV-amcatnloFXFX-pythia8",getDirList("/eos/uscms/store/user/shalhout/ZZTo4L_13TeV-amcatnloFXFX-pythia8/Moriond17_GenBosonFixTry1/"),"VV"],
            ["WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8",getDirList("/eos/uscms/store/user/gfunk/WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8",getDirList("/eos/uscms/store/user/gfunk/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8",getDirList("/eos/uscms/store/user/gfunk/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8",getDirList("/eos/uscms/store/user/gfunk/VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8",getDirList("/eos/uscms/store/user/gfunk/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8",getDirList("/eos/uscms/store/user/gfunk/WWZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8",getDirList("/eos/uscms/store/user/gfunk/WZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8",getDirList("/eos/uscms/store/user/gfunk/ZZZ_TuneCUETP8M1_13TeV-amcatnlo-pythia8/Moriond17_BTAGFIXtry1/"),"VV"],
            ["ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1",getDirList("/eos/uscms/store/user/gfunk/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/Moriond17_BTAGFIXtry1/"),"VV"],
            ["ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1",getDirList("/eos/uscms/store/user/gfunk/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/Moriond17_BTAGFIXtry1/"),"VV"],
            ["ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1",getDirList("/eos/uscms/store/user/shalhout/ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1/Moriond17_GenBosonFixTry1/"),"VV"],
            ["ST_t-channel_top_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1",getDirList("/eos/uscms/store/user/shalhout/ST_t-channel_top_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1/Moriond17_GenBosonFixTry1/"),"VV"]
            ]

print bkgDirLists

def makeList(char):
  for i in range(1,len(char.split(','))):
    print 'ls /eos/uscms' + char.split(',')[i] + ' > ./tempList' + str(i) + '.txt.tmp'
    subprocess.call('ls /eos/uscms' + char.split(',')[i] + ' > ./tempList' + str(i) + '.txt.tmp' , shell = True)
    currFileTmp = open('tempList' + str(i) + '.txt.tmp','r')
    currFileOut = open('tempList' + str(i) + '.txt','w')
    for line in currFileTmp:
      if 'root' in line:
        line = 'root://cmsxrootd.fnal.gov/' + char.split(',')[i] + line
        currFileOut.write(line)
    currFileTmp.close()
    currFileOut.close()
    os.remove('tempList' + str(i) + '.txt.tmp')
  tempFileList = ""
  for i in range(1,len(char.split(','))):
    tempFileList += "tempList" + str(i) + ".txt "
  subprocess.call('cat ' + tempFileList + '> ' + "FullListTemp.txt" , shell = True)
  subprocess.call('rm ' + tempFileList, shell = True)
  longFileList = open('FullListTemp.txt','r')
  fileListsFinal = open(char.split(',')[0] + "_GROUP0" + ".txt",'w')
  lineIndex = 0
  fileIndex = 0
  for line in longFileList:
    fileListsFinal.write(line)
    lineIndex += 1
    if lineIndex > (filesPerJob - 1):
      fileListsFinal.close()
      lineIndex = 0
      fileIndex +=1
      fileListsFinal = open(char.split(',')[0] + "_GROUP" + str(fileIndex) + ".txt",'w')
  fileListsFinal.close()
  longFileList.close()
  os.remove('FullListTemp.txt')
  return fileIndex


print "Sync Tree Operation Submissions: "

for i in range (0,len(bkgDirLists)):
  fullDirName = topDirName + bkgDirLists[i][2] + '/' + bkgDirLists[i][0] + '/'
  fileListName = bkgDirLists[i][0] + "_FlatTuple_LIST"
  inChar = fileListName
  for j in range (0,len(bkgDirLists[i][1])):
    inChar += "," + str(bkgDirLists[i][1][j])
  numberOfLists = makeList(inChar) + 1
  for j in range(0,numberOfLists):
    fullDirName = topDirName + bkgDirLists[i][2] + '/' + bkgDirLists[i][0] + '/CondorJob' + str(j) + '/'
    fileListName = bkgDirLists[i][0] + "_FlatTuple_LIST_GROUP" + str(j)
    print "_____________________________________________New Submit_____________________________________________" + '\n'
    print "python operation_submit.py -c -t \"BASELINE/FlatTuple\" -i " + str(fileListName) + ".txt" + " -o generateH2TauSyncTree -d " + str(fullDirName) + '\n'
    subprocess.call("python operation_submit.py -c -t \"BASELINE/FlatTuple\" -i " + str(fileListName) + ".txt" + " -o generateH2TauSyncTree -d " + str(fullDirName) + '\n', shell = True)

time.sleep(1)
print 'Issue command after all jobs are running: mv *FlatTuple_LIST_GROUP* ' + storageDirName + ' '
#subprocess.call('mv *FlatTuple_LIST_GROUP* ' + storageDirName, shell = True)
