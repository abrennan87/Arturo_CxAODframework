#!/usr/bin/python

import os, math, sys

#############################
#
# Script for copying grid-job output-files (CxAODs) to EOS.
#
# Sub-directories are created on EOS to group the files into samples.
#
# VERY IMPORTANT :
# Execute in the directory where you have dq2-get your jobs.
#
#############################

#############################
# parameters
#############################

# only print commands instead of executing them
test_only = True

# skip existing files (also if being corrupt, e.g. size 0)
skip_existing = True

# to copy the samples to an eos directory
main_path = "/eos/atlas/atlasgroupdisk/phys-higgs/HSG5/Run2/VH/"
# to copy the samples to a local directory
#main_path = "/afs/.../"

# determines full output path (full_path)
energy_tag     = "13TeV"
samples_tag    = "p1784"
derivation_tag = "HIGG5D1"
production_tag = "00-07-00"

#############################
# sample definition
#############################

our_samples = [
# sample		1st match		2nd match
["muonData",		"physics_Muons",	""],
["egammaData",		"physics_Egamma",	""],
["metData",		"physics_JetTauEtmiss",	""],
["ZeeB",		"ZeeMassiveCBPt",	"BFilter"],
["ZeeC",		"ZeeMassiveCBPt",	"CFilterBVeto"],
["ZeeL",		"ZeeMassiveCBPt",	"CVetoBVeto"],
["ZmumuB",		"ZmumuMassiveCBPt",	"BFilter"],
["ZmumuC",		"ZmumuMassiveCBPt",	"CFilterBVeto"],
["ZmumuL",		"ZmumuMassiveCBPt",	"CVetoBVeto"],
["ZtautauB",		"ZtautauMassiveCBPt",	"BFilter"],
["ZtautauC",		"ZtautauMassiveCBPt",	"CFilterBVeto"],
["ZtautauL",		"ZtautauMassiveCBPt",	"CVetoBVeto"],
["ZnunuB",		"ZnunuMassiveCBPt",	"BFilter"],
["ZnunuC",		"ZnunuMassiveCBPt",	"CFilterBVeto"],
["ZnunuL",		"ZnunuMassiveCBPt",	"CVetoBVeto"],
["WenuB",		"WenuMassiveCBPt",	"BFilter"],
["WenuC",		"WenuMassiveCBPt",	"CJetFilterBVeto"],
["WenuL",		"WenuMassiveCBPt",	"CJetVetoBVeto"],
["WmunuB",		"WmunuMassiveCBPt",	"BFilter"],
["WmunuC",		"WmunuMassiveCBPt",	"CJetFilterBVeto"],
["WmunuL",		"WmunuMassiveCBPt",	"CJetVetoBVeto"],
["WtaunuB",		"WtaunuMassiveCBPt",	"BFilter"],
["WtaunuC",		"WtaunuMassiveCBPt",	"CJetFilterBVeto"],
["WtaunuL",		"WtaunuMassiveCBPt",	"CJetVetoBVeto"],
["ttbar",		"ttbar",		""],
["singletop_t",		"_tchan",		""],
["singletop_s",		"_schan",		""],
["singletop_Wt",	"_Wtchan",		""],
["ZHvv125",		"ZH125_nunubb",		""],
["WH125",		"WH125_lnubb",		""],
["ZHll125",		"ZH125_llbb",		""],
]


#############################
# code
#############################

is_eos = ("/eos/" in main_path)
ana_dir = derivation_tag + "_" + energy_tag + "_" + samples_tag + "/"
prod_dir = "CxAOD_" + production_tag + "/"
full_path = main_path + ana_dir + prod_dir

def makeDir(path):
  if (is_eos) : command = "xrd eosatlas.cern.ch mkdir " + path
  else :     command = "mkdir " + path
  print command
  if not test_only : os.system(command)


if __name__ == "__main__":

  print "Going to copy files from current directory to", full_path

  # make sample dirs

  makeDir(main_path + ana_dir)
  makeDir(full_path)
  for our_sample in our_samples :
    makeDir(full_path + our_sample[0]+"/")

  # loop over subdirs in current dir

  for subdir, dirs, files in os.walk(".") :

    print "Directory:", subdir

    # determine sample

    sample = "Unknown"
    for our_sample in our_samples :
      if not our_sample[1] in subdir : continue
      if not our_sample[2] in subdir : continue
      sample = our_sample[0]
    if sample is "Unknown":
      print "Warning: could not determine sample from directory'" + subdir + "'. Skipping."
      continue
    print "Sample:", sample

    final_path = full_path + sample + "/" + subdir + "/"
    makeDir(final_path)

    # loop over files in current subdir and copy

    for file in files :
      file_path = subdir + "/" + file
      print "File:", file
      if (is_eos) :
        command = "xrdcp "
        if not skip_existing : command += "--force "
        command += file_path + " root://eosatlas.cern.ch/" + final_path + file
      else :
        command = "cp "
        if skip_existing : command += "-u "
        command += file_path + " "+ final_path
      if test_only : print command
      else :         os.system(command)
      
  print "Copied files from current directory to", full_path
  print "Done!"

