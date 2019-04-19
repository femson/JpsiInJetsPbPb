#define makeAccEff_cxx
#define _USE_MATH_DEFINES
#include "makeAccEff_centr.h"
//#include "compAccEff.C"
//#include "systAccEff.C"

Double_t ptbins []= {3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0, 5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.5, 9.0, 9.5, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 20.0, 25.0, 30.0, 40.0, 50};
Double_t ybins []= {-2.4, -2.0, -1.6, -1.2, -0.8, -0.4, 0.0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4};


void oniaTree::AccEffCalc()
{ 
  int nptbins = sizeof(ptbins)/sizeof(double)-1;
  int nybins = sizeof(ybins)/sizeof(double)-1;
  
  cout << "[INFO] Importing the numerators and denominators of the corrections." << endl;

  TFile*prAccFile_pbpb = TFile::Open("FilesAccxEff/Acc/prAccHists_PbPb.root");
  TFile*nprAccFile_pbpb = TFile::Open("FilesAccxEff/Acc/nprAccHists_PbPb.root");
  TFile*prEffFile_pbpb = TFile::Open("FilesAccxEff/Eff/prEffHists_PbPb.root");
  TFile*nprEffFile_pbpb = TFile::Open("FilesAccxEff/Eff/nprEffHists_PbPb.root");

  if (!prAccFile_pbpb) cout << "AccEffCalc() could not be executed for prompt PbPb since no PbPb prompt acceptance file was found. Try AccCalc() to create the file." << endl;
  if (!prEffFile_pbpb) cout << "AccEffCalc() could not be executed for prompt PbPb since no PbPb prompt efficiency file was found. Try EffCalc() to create the file." << endl;
  if (!nprAccFile_pbpb) cout << "AccEffCalc() could not be executed for non-prompt PbPb since no PbPb non-prompt acceptance file was found. Try AccCalc() to create the file." << endl;
  if (!nprEffFile_pbpb) cout << "AccEffCalc() could not be executed for non-prompt PbPb since no PbPb non-prompt efficiency file was found. Try EffCalc() to create the file." << endl;

  // prompt calculations
  if (prAccFile_pbpb && prEffFile_pbpb)
    {
      // 0-10% centrality
      TH2F *prAccNum_pbpb_10  = (TH2F*) prAccFile_pbpb->Get("num_0_10_2d_nominal");
      TH2F *prAccDen_pbpb_10  = (TH2F*) prAccFile_pbpb->Get("deno_0_10_2d");
      TH2F *prEffNum_pbpb_10  = (TH2F*) prEffFile_pbpb->Get("num_0_10_2d_nominal");
      TH2F *prEffDen_pbpb_10  = (TH2F*) prEffFile_pbpb->Get("deno_0_10_2d");
      prAccNum_pbpb_10->Multiply(prEffNum_pbpb_10);
      prAccDen_pbpb_10->Multiply(prEffDen_pbpb_10);
      
      TEfficiency* prCorr_pbpb_10 = new TEfficiency("prCorr_pp_10", "AccxEff(y,pt), 0-10%; y; pt; eff", nybins, ybins, nptbins, ptbins);
      prCorr_pbpb_10->SetStatisticOption(TEfficiency::kBBayesian);
      prCorr_pbpb_10->SetPassedHistogram(*prAccNum_pbpb_10,"f");
      prCorr_pbpb_10->SetTotalHistogram(*prAccDen_pbpb_10,"f");
      prCorr_pbpb_10->SetName("corr_Jpsi_PbPb_pr_0_10");

      // 10-30% centrality
      TH2F *prAccNum_pbpb_30  = (TH2F*) prAccFile_pbpb->Get("num_10_30_2d_nominal");
      TH2F *prAccDen_pbpb_30  = (TH2F*) prAccFile_pbpb->Get("deno_10_30_2d");
      TH2F *prEffNum_pbpb_30  = (TH2F*) prEffFile_pbpb->Get("num_10_30_2d_nominal");
      TH2F *prEffDen_pbpb_30  = (TH2F*) prEffFile_pbpb->Get("deno_10_30_2d");
      prAccNum_pbpb_30->Multiply(prEffNum_pbpb_30);
      prAccDen_pbpb_30->Multiply(prEffDen_pbpb_30);
      
      TEfficiency* prCorr_pbpb_30 = new TEfficiency("prCorr_pp_30", "AccxEff(y,pt), 10-30%; y; pt; eff", nybins, ybins, nptbins, ptbins);
      prCorr_pbpb_30->SetStatisticOption(TEfficiency::kBBayesian);
      prCorr_pbpb_30->SetPassedHistogram(*prAccNum_pbpb_30,"f");
      prCorr_pbpb_30->SetTotalHistogram(*prAccDen_pbpb_30,"f");
      prCorr_pbpb_30->SetName("corr_Jpsi_PbPb_pr_10_30");

      // 30-100% centrality
      TH2F *prAccNum_pbpb_100  = (TH2F*) prAccFile_pbpb->Get("num_30_100_2d_nominal");
      TH2F *prAccDen_pbpb_100  = (TH2F*) prAccFile_pbpb->Get("deno_30_100_2d");
      TH2F *prEffNum_pbpb_100  = (TH2F*) prEffFile_pbpb->Get("num_30_100_2d_nominal");
      TH2F *prEffDen_pbpb_100  = (TH2F*) prEffFile_pbpb->Get("deno_30_100_2d");
      prAccNum_pbpb_100->Multiply(prEffNum_pbpb_100);
      prAccDen_pbpb_100->Multiply(prEffDen_pbpb_100);
      
      TEfficiency* prCorr_pbpb_100 = new TEfficiency("prCorr_pp_100", "AccxEff(y,pt), 30-100%; y; pt; eff", nybins, ybins, nptbins, ptbins);
      prCorr_pbpb_100->SetStatisticOption(TEfficiency::kBBayesian);
      prCorr_pbpb_100->SetPassedHistogram(*prAccNum_pbpb_100,"f");
      prCorr_pbpb_100->SetTotalHistogram(*prAccDen_pbpb_100,"f");
      prCorr_pbpb_100->SetName("corr_Jpsi_PbPb_pr_30_100");

      TFile* fsave_pr = new TFile("FilesAccxEff/pr_correction_AccEff_centr.root","RECREATE");
      prCorr_pbpb_10->Write("corr_Jpsi_PbPb_pr_0_10");
      prCorr_pbpb_30->Write("corr_Jpsi_PbPb_pr_10_30");
      prCorr_pbpb_100->Write("corr_Jpsi_PbPb_pr_30_100");
      fsave_pr->Close(); 
    }

  // non-prompt calculations
  if (nprAccFile_pbpb && nprEffFile_pbpb)
    {
      // 0-10% centrality
      TH2F *nprAccNum_pbpb_10 = (TH2F*) nprAccFile_pbpb->Get("num_0_10_2d_nominal");
      TH2F *nprAccDen_pbpb_10 = (TH2F*) nprAccFile_pbpb->Get("deno_0_10_2d");
      TH2F *nprEffNum_pbpb_10 = (TH2F*) nprEffFile_pbpb->Get("num_0_10_2d_nominal");
      TH2F *nprEffDen_pbpb_10 = (TH2F*) nprEffFile_pbpb->Get("deno_0_10_2d");
      nprAccNum_pbpb_10->Multiply(nprEffNum_pbpb_10);
      nprAccDen_pbpb_10->Multiply(nprEffDen_pbpb_10);
      
      TEfficiency* nprCorr_pbpb_10 = new TEfficiency("nprCorr_pbpb_10", "AccxEff(y,pt), 0-10%; y; pt; eff", nybins, ybins, nptbins, ptbins);
      nprCorr_pbpb_10->SetStatisticOption(TEfficiency::kBBayesian);
      nprCorr_pbpb_10->SetPassedHistogram(*nprAccNum_pbpb_10,"f");
      nprCorr_pbpb_10->SetTotalHistogram(*nprAccDen_pbpb_10,"f");
      nprCorr_pbpb_10->SetName("corr_Jpsi_PbPb_npr_0_10");

      // 10-30% centrality
      TH2F *nprAccNum_pbpb_30 = (TH2F*) nprAccFile_pbpb->Get("num_10_30_2d_nominal");
      TH2F *nprAccDen_pbpb_30 = (TH2F*) nprAccFile_pbpb->Get("deno_10_30_2d");
      TH2F *nprEffNum_pbpb_30 = (TH2F*) nprEffFile_pbpb->Get("num_10_30_2d_nominal");
      TH2F *nprEffDen_pbpb_30 = (TH2F*) nprEffFile_pbpb->Get("deno_10_30_2d");
      nprAccNum_pbpb_30->Multiply(nprEffNum_pbpb_30);
      nprAccDen_pbpb_30->Multiply(nprEffDen_pbpb_30);
      
      TEfficiency* nprCorr_pbpb_30 = new TEfficiency("nprCorr_pbpb_30", "AccxEff(y,pt), 10-30%; y; pt; eff", nybins, ybins, nptbins, ptbins);
      nprCorr_pbpb_30->SetStatisticOption(TEfficiency::kBBayesian);
      nprCorr_pbpb_30->SetPassedHistogram(*nprAccNum_pbpb_30,"f");
      nprCorr_pbpb_30->SetTotalHistogram(*nprAccDen_pbpb_30,"f");
      nprCorr_pbpb_30->SetName("corr_Jpsi_PbPb_npr_10_30");
      
      // 30-100% centrality
      TH2F *nprAccNum_pbpb_100 = (TH2F*) nprAccFile_pbpb->Get("num_30_100_2d_nominal");
      TH2F *nprAccDen_pbpb_100 = (TH2F*) nprAccFile_pbpb->Get("deno_30_100_2d");
      TH2F *nprEffNum_pbpb_100 = (TH2F*) nprEffFile_pbpb->Get("num_30_100_2d_nominal");
      TH2F *nprEffDen_pbpb_100 = (TH2F*) nprEffFile_pbpb->Get("deno_30_100_2d");
      nprAccNum_pbpb_100->Multiply(nprEffNum_pbpb_100);
      nprAccDen_pbpb_100->Multiply(nprEffDen_pbpb_100);
      
      TEfficiency* nprCorr_pbpb_100 = new TEfficiency("nprCorr_pbpb_100", "AccxEff(y,pt), 30-100%; y; pt; eff", nybins, ybins, nptbins, ptbins);
      nprCorr_pbpb_100->SetStatisticOption(TEfficiency::kBBayesian);
      nprCorr_pbpb_100->SetPassedHistogram(*nprAccNum_pbpb_100,"f");
      nprCorr_pbpb_100->SetTotalHistogram(*nprAccDen_pbpb_100,"f");
      nprCorr_pbpb_100->SetName("corr_Jpsi_PbPb_npr_30_100");

      TFile* fsave_npr = new TFile("FilesAccxEff/npr_correction_AccEff_centr.root","RECREATE");
      nprCorr_pbpb_10->Write("corr_Jpsi_PbPb_npr_0_10");
      nprCorr_pbpb_30->Write("corr_Jpsi_PbPb_npr_10_30");
      nprCorr_pbpb_100->Write("corr_Jpsi_PbPb_npr_30_100");
      fsave_npr->Close(); 
    }
}


void oniaTree::EffCalc () {  
  int nptbins = sizeof(ptbins)/sizeof(double)-1;
  int nybins  = sizeof(ybins)/sizeof(double)-1;

  //for centrality 0-10%  
  TH1F* deno10_pt = new TH1F ("deno10_pt", "N_{gen} vs p_{T}, 0-10%; p_{T}; N_{total}", nptbins, ptbins); deno10_pt->Sumw2();
  TH1F* num10_pt  = new TH1F ("num10_pt", "N_{reco} vs p_{T}, 0-10%; p_{T}; N_{reco}", nptbins, ptbins); num10_pt->Sumw2();
  TH1F* deno10_y  = new TH1F ("deno10_y","N_{gen} vs y, 0-10%; y; N_{total}", nybins, ybins); deno10_y->Sumw2();
  TH1F* num10_y   = new TH1F ("num10_y","N_{reco} vs y, 0-10%; y; N_{reco}", nybins, ybins); num10_y->Sumw2();
  
  TH2F* deno10_pty           = new TH2F ("deno10_pty", "N_{gen} vs p_{T} and y, 0-10%; y; p_{T}; N_{total}", nybins, ybins, nptbins, ptbins); deno10_pty->Sumw2();
  TH2F* num10_noweights      = new TH2F ("num10_noweights", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_noweights->Sumw2();
  TH2F* num10_nominal        = new TH2F ("num10_nominal", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_nominal->Sumw2();
  TH2F* num10_binned         = new TH2F ("num10_binned", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_binned->Sumw2();
  TH2F* num10_plus1sig       = new TH2F ("num10_plus1sig", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_plus1sig->Sumw2();
  TH2F* num10_min1sig        = new TH2F ("num10_min1sig", "N_{reco}vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_min1sig->Sumw2();
  TH2F* num10_muid_sta       = new TH2F ("num10_muid_sta", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_muid_sta->Sumw2();
  TH2F* num10_muid           = new TH2F ("num10_muid", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_muid->Sumw2();
  TH2F* num10_muid_plus1sig  = new TH2F ("num10_muid_plus1sig", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_muid_plus1sig->Sumw2();
  TH2F* num10_muid_min1sig   = new TH2F ("num10_muid_min1sig", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_muid_min1sig->Sumw2();
  TH2F* num10_sta            = new TH2F ("num10_sta", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_sta->Sumw2();
  TH2F* num10_sta_plus1sig   = new TH2F ("num10_sta_plus1sig", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_sta_plus1sig->Sumw2();
  TH2F* num10_sta_min1sig    = new TH2F ("num10_sta_min1sig", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_sta_min1sig->Sumw2();
  TH2F* num10_trk_plus1sig   = new TH2F ("num10_trk_plus1sig", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_trk_plus1sig->Sumw2();
  TH2F* num10_trk_min1sig    = new TH2F ("num10_trk_min1sig", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_trk_min1sig->Sumw2();
  

  //for centrality 10-30%  
  TH1F* deno30_pt = new TH1F ("deno30_pt", "N_{gen} vs p_{T}, 10-30%; p_{T}; N_{total}", nptbins, ptbins); deno30_pt->Sumw2();
  TH1F* num30_pt  = new TH1F ("num30_pt", "N_{reco} vs p_{T}, 10-30%; p_{T}; N_{reco}", nptbins, ptbins); num30_pt->Sumw2();
  TH1F* deno30_y  = new TH1F ("deno30_y","N_{gen} vs y, 10-30%; y; N_{total}", nybins, ybins); deno30_y->Sumw2();
  TH1F* num30_y   = new TH1F ("num30_y","N_{reco} vs y, 10-30%; y; N_{reco}", nybins, ybins); num30_y->Sumw2();
  
  TH2F* deno30_pty           = new TH2F ("deno30_pty", "N_{gen} vs p_{T} and y, 10-30%; y; p_{T}; N_{total}", nybins, ybins, nptbins, ptbins); deno30_pty->Sumw2();
  TH2F* num30_noweights      = new TH2F ("num30_noweights", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_noweights->Sumw2();
  TH2F* num30_nominal        = new TH2F ("num30_nominal", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_nominal->Sumw2();
  TH2F* num30_binned         = new TH2F ("num30_binned", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_binned->Sumw2();
  TH2F* num30_plus1sig       = new TH2F ("num30_plus1sig", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_plus1sig->Sumw2();
  TH2F* num30_min1sig        = new TH2F ("num30_min1sig", "N_{reco}vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_min1sig->Sumw2();
  TH2F* num30_muid_sta       = new TH2F ("num30_muid_sta", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_muid_sta->Sumw2();
  TH2F* num30_muid           = new TH2F ("num30_muid", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_muid->Sumw2();
  TH2F* num30_muid_plus1sig  = new TH2F ("num30_muid_plus1sig", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_muid_plus1sig->Sumw2();
  TH2F* num30_muid_min1sig   = new TH2F ("num30_muid_min1sig", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_muid_min1sig->Sumw2();
  TH2F* num30_sta            = new TH2F ("num30_sta", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_sta->Sumw2();
  TH2F* num30_sta_plus1sig   = new TH2F ("num30_sta_plus1sig", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_sta_plus1sig->Sumw2();
  TH2F* num30_sta_min1sig    = new TH2F ("num30_sta_min1sig", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_sta_min1sig->Sumw2();
  TH2F* num30_trk_plus1sig   = new TH2F ("num30_trk_plus1sig", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_trk_plus1sig->Sumw2();
  TH2F* num30_trk_min1sig    = new TH2F ("num30_trk_min1sig", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_trk_min1sig->Sumw2();


  //for centrality 30-100%  
  TH1F* deno100_pt = new TH1F ("deno100_pt", "N_{gen} vs p_{T}, 30-100%; p_{T}; N_{total}", nptbins, ptbins); deno100_pt->Sumw2();
  TH1F* num100_pt  = new TH1F ("num100_pt", "N_{reco} vs p_{T}, 30-100%; p_{T}; N_{reco}", nptbins, ptbins); num100_pt->Sumw2();
  TH1F* deno100_y  = new TH1F ("deno100_y","N_{gen} vs y, 30-100%; y; N_{total}", nybins, ybins); deno100_y->Sumw2();
  TH1F* num100_y   = new TH1F ("num100_y","N_{reco} vs y, 30-100%; y; N_{reco}", nybins, ybins); num100_y->Sumw2();
  
  TH2F* deno100_pty           = new TH2F ("deno100_pty", "N_{gen} vs p_{T} and y, 30-100%; y; p_{T}; N_{total}", nybins, ybins, nptbins, ptbins); deno100_pty->Sumw2();
  TH2F* num100_noweights      = new TH2F ("num100_noweights", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_noweights->Sumw2();
  TH2F* num100_nominal        = new TH2F ("num100_nominal", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_nominal->Sumw2();
  TH2F* num100_binned         = new TH2F ("num100_binned", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_binned->Sumw2();
  TH2F* num100_plus1sig       = new TH2F ("num100_plus1sig", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_plus1sig->Sumw2();
  TH2F* num100_min1sig        = new TH2F ("num100_min1sig", "N_{reco}vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_min1sig->Sumw2();
  TH2F* num100_muid_sta       = new TH2F ("num100_muid_sta", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_muid_sta->Sumw2();
  TH2F* num100_muid           = new TH2F ("num100_muid", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_muid->Sumw2();
  TH2F* num100_muid_plus1sig  = new TH2F ("num100_muid_plus1sig", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_muid_plus1sig->Sumw2();
  TH2F* num100_muid_min1sig   = new TH2F ("num100_muid_min1sig", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_muid_min1sig->Sumw2();
  TH2F* num100_sta            = new TH2F ("num100_sta", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_sta->Sumw2();
  TH2F* num100_sta_plus1sig   = new TH2F ("num100_sta_plus1sig", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_sta_plus1sig->Sumw2();
  TH2F* num100_sta_min1sig    = new TH2F ("num100_sta_min1sig", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_sta_min1sig->Sumw2();
  TH2F* num100_trk_plus1sig   = new TH2F ("num100_trk_plus1sig", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_trk_plus1sig->Sumw2();
  TH2F* num100_trk_min1sig    = new TH2F ("num100_trk_min1sig", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_trk_min1sig->Sumw2();


  Long64_t nentries = fChain->GetEntries();
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry = 0; jentry < nentries; jentry++)
    {
      if (jentry%10000==0) cout<<"[INFO] "<<jentry*100/nentries<<"% finished"<<'\r'<<flush;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      for (int iQQ=0; iQQ<Gen_QQ_size; iQQ++)
	{
	  //cout<< "eventNb = "<<eventNb<<endl;
	  //cout << "Gen_QQ_size = " << Gen_QQ_size << ", Gen_mu_size = " << Gen_mu_size<<endl;
	  //cout << "Reco_QQ_size = " << Reco_QQ_size << ", Reco_mu_size = " << Reco_mu_size<<endl; 
	  TLorentzVector *GenQQ4mom = (TLorentzVector*) Gen_QQ_4mom->At(iQQ);
	  jpsi_m=GenQQ4mom->M();
	  jpsi_pt = GenQQ4mom->Pt();
	  jpsi_rap = GenQQ4mom->Rapidity();

	  if (jpsi_pt < 3 || jpsi_pt > 50) continue;
	  if (fabs(jpsi_rap) >= 2.4) continue;
	  if (!areGenMuonsInAcceptance2019(iQQ)) continue;

	  if (hiBin <= 20) // for 0-10%
	    {
	      deno10_pty->Fill(jpsi_rap, jpsi_pt);
	      deno10_pt->Fill(jpsi_pt);
	      if (jpsi_pt >= 6.5) deno10_y->Fill(fabs(jpsi_rap));
	    }	 

	  if (hiBin > 20 && hiBin <= 60) // for 10-30%
	    {
	      deno30_pty->Fill(jpsi_rap, jpsi_pt);
	      deno30_pt->Fill(jpsi_pt);
	      if (jpsi_pt >= 6.5) deno30_y->Fill(fabs(jpsi_rap));
	    }	 

	  if (hiBin > 60 && hiBin <= 200) // for 30-100%
	    {
	      deno100_pty->Fill(jpsi_rap, jpsi_pt);
	      deno100_pt->Fill(jpsi_pt);
	      if (jpsi_pt >= 6.5) deno100_y->Fill(fabs(jpsi_rap));
	    }	 

	  int whichRec = Gen_QQ_whichRec[iQQ];
	  if (whichRec < 0) continue;
	  //cout <<"Matched, Gen_QQ_whichRec[iQQ] = "<<Gen_QQ_whichRec[iQQ]<<endl;
	  TLorentzVector *RecoQQ4mom = (TLorentzVector*) Reco_QQ_4mom->At(whichRec);
	  
	  if (!areMuonsInAcceptance2019(whichRec)) continue;
	  if (!passQualityCuts2019(whichRec)) continue;
	  if (!isTriggerMatch(whichRec, triggerIndex_PP)) continue;
	  if (Reco_QQ_sign[whichRec]!=0) continue;
	  if (RecoQQ4mom->Pt()<3 || RecoQQ4mom->Pt()>50) continue;
	  if (fabs(RecoQQ4mom->Rapidity())>=2.4) continue;
	  if (RecoQQ4mom->M()<2.6 || RecoQQ4mom->M()>3.5) continue;
	  if (isPbPb && !(pprimaryVertexFilter && pBeamScrapingFilter && phfCoincFilter2Th4)) continue;
	  if (!isPbPb && !(pPAprimaryVertexFilter && pBeamScrapingFilter)) continue;

	  TLorentzVector *RecoQQmupl4mom = (TLorentzVector*) Reco_mu_4mom->At(Reco_QQ_mupl_idx[whichRec]);
	  TLorentzVector *RecoQQmumi4mom = (TLorentzVector*) Reco_mu_4mom->At(Reco_QQ_mumi_idx[whichRec]);
	  
	  tnp_weight=1.0;

	  if (hiBin <= 20) // for 0-10%
	    {
	      num10_noweights->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt());
	      
	      //nominal
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_nominal->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      //systematics
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-10) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-10) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_binned->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-1) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-1) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-2) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-2) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_muid_sta->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_muid->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-1) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-1) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_muid_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-2) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-2) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_muid_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_sta->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-1) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-1) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_sta_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-2) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-2) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num10_sta_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	  
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(-1) * tnp_weight_trk_pp(-1);
	      num10_trk_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(-2) * tnp_weight_trk_pp(-2);
	      num10_trk_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      num10_pt->Fill(RecoQQ4mom->Pt());
	      if (RecoQQ4mom->Pt() >= 6.5) num10_y->Fill(fabs(RecoQQ4mom->Rapidity()));
	      continue;
	    }

	  if (hiBin > 20 && hiBin <= 60) // for 10-30%
	    {
	      num30_noweights->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt());

	      //nominal
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_nominal->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      //systematics
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-10) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-10) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_binned->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-1) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-1) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-2) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-2) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_muid_sta->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_muid->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-1) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-1) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_muid_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-2) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-2) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_muid_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_sta->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-1) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-1) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_sta_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-2) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-2) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num30_sta_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	  
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(-1) * tnp_weight_trk_pp(-1);
	      num30_trk_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(-2) * tnp_weight_trk_pp(-2);
	      num30_trk_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      num30_pt->Fill(RecoQQ4mom->Pt());
	      if (RecoQQ4mom->Pt() >= 6.5) num30_y->Fill(fabs(RecoQQ4mom->Rapidity()));
	      continue;
	    }

	  if (hiBin > 60 && hiBin <= 200) // for 30-100%
	    {
	      num100_noweights->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt());
	      
	      //nominal
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_nominal->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      //systematics
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-10) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-10) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_binned->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-1) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-1) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-2) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-2) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_muid_sta->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_muid->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-1) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-1) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_muid_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_muid_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-2) * tnp_weight_muid_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-2) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_muid_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_sta->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-1) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-1) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_sta_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_sta_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),-2) * tnp_weight_sta_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),-2) *
		tnp_weight_trk_pp(0) * tnp_weight_trk_pp(0);
	      num100_sta_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	  
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(-1) * tnp_weight_trk_pp(-1);
	      num100_trk_plus1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      tnp_weight = tnp_weight_trg_pp(RecoQQmupl4mom->Pt(),RecoQQmupl4mom->Eta(),0) * tnp_weight_trg_pp(RecoQQmumi4mom->Pt(),RecoQQmumi4mom->Eta(),0) *
		tnp_weight_trk_pp(-2) * tnp_weight_trk_pp(-2);
	      num100_trk_min1sig->Fill(RecoQQ4mom->Rapidity(), RecoQQ4mom->Pt(), tnp_weight);
	      
	      num100_pt->Fill(RecoQQ4mom->Pt());
	      if (RecoQQ4mom->Pt() >= 6.5) num100_y->Fill(fabs(RecoQQ4mom->Rapidity()));
	      continue;
	    }
	}
    }

  gSystem->mkdir("FilesAccxEff");  
  gSystem->mkdir("FilesAccxEff/Eff");
  
  TFile* fsave = new TFile (Form("FilesAccxEff/Eff/%sEffHists_%s.root", isPr?"pr":"npr",isPbPb?"PbPb":"PP"), "RECREATE");
  
  deno10_pty->Write("deno_0_10_2d"); deno10_pt->Write("deno_0_10_pt"); deno10_y->Write("deno_0_10_y");
  num10_nominal->Write("num_0_10_2d_nominal"); num10_binned->Write("num_0_10_2d_binned"); num10_plus1sig->Write("num_0_10_2d_trg_plus1sig");
  num10_min1sig->Write("num_0_10_2d_trg_minus1sig"); num10_muid_sta->Write("num_0_10_2d_muid_sta"); num10_muid->Write("num_0_10_2d_muid");
  num10_muid_plus1sig->Write("num_0_10_2d_muid_plus1sig"); num10_muid_min1sig->Write("num_0_10_2d_muid_minus1sig"); num10_sta->Write("num_0_10_2d_sta");
  num10_sta_plus1sig->Write("num_0_10_2d_sta_plus1sig"); num10_sta_min1sig->Write("num_0_10_2d_sta_minus1sig"); num10_trk_plus1sig->Write("num_0_10_2d_trk_plus1sig");
  num10_trk_min1sig->Write("num_0_10_2d_trk_minus1sig"); num10_noweights->Write("num_0_10_2d_noweights");
  num10_pt->Write("num_0_10_pt"); num10_y->Write("num_0_10_y");

  deno30_pty->Write("deno_10_30_2d"); deno30_pt->Write("deno_10_30_pt"); deno30_y->Write("deno_10_30_y");
  num30_nominal->Write("num_10_30_2d_nominal"); num30_binned->Write("num_10_30_2d_binned"); num30_plus1sig->Write("num_10_30_2d_trg_plus1sig");
  num30_min1sig->Write("num_10_30_2d_trg_minus1sig"); num30_muid_sta->Write("num_10_30_2d_muid_sta"); num30_muid->Write("num_10_30_2d_muid");
  num30_muid_plus1sig->Write("num_10_30_2d_muid_plus1sig"); num30_muid_min1sig->Write("num_10_30_2d_muid_minus1sig"); num30_sta->Write("num_10_30_2d_sta");
  num30_sta_plus1sig->Write("num_10_30_2d_sta_plus1sig"); num30_sta_min1sig->Write("num_10_30_2d_sta_minus1sig"); num30_trk_plus1sig->Write("num_10_30_2d_trk_plus1sig");
  num30_trk_min1sig->Write("num_10_30_2d_trk_minus1sig"); num30_noweights->Write("num_10_30_2d_noweights");
  num30_pt->Write("num_10_30_pt"); num30_y->Write("num_10_30_y");

  deno100_pty->Write("deno_30_100_2d"); deno100_pt->Write("deno_30_100_pt"); deno100_y->Write("deno_30_100_y");
  num100_nominal->Write("num_30_100_2d_nominal"); num100_binned->Write("num_30_100_2d_binned"); num100_plus1sig->Write("num_30_100_2d_trg_plus1sig");
  num100_min1sig->Write("num_30_100_2d_trg_minus1sig"); num100_muid_sta->Write("num_30_100_2d_muid_sta"); num100_muid->Write("num_30_100_2d_muid");
  num100_muid_plus1sig->Write("num_30_100_2d_muid_plus1sig"); num100_muid_min1sig->Write("num_30_100_2d_muid_minus1sig"); num100_sta->Write("num_30_100_2d_sta");
  num100_sta_plus1sig->Write("num_30_100_2d_sta_plus1sig"); num100_sta_min1sig->Write("num_30_100_2d_sta_minus1sig"); num100_trk_plus1sig->Write("num_30_100_2d_trk_plus1sig");
  num100_trk_min1sig->Write("num_30_100_2d_trk_minus1sig"); num100_noweights->Write("num_30_100_2d_noweights");
  num100_pt->Write("num_30_100_pt"); num100_y->Write("num_30_100_y");


  fsave->Close();
  
  delete fsave;
  delete deno10_pt; delete num10_pt; delete deno10_y; delete num10_y; delete deno10_pty; delete num10_noweights; delete num10_nominal; delete num10_binned; delete num10_plus1sig; delete num10_min1sig; delete num10_muid_sta; delete num10_muid; delete num10_muid_plus1sig; delete num10_muid_min1sig; delete num10_sta; delete num10_sta_plus1sig; delete num10_sta_min1sig; delete num10_trk_plus1sig; delete num10_trk_min1sig;
  delete deno30_pt; delete num30_pt; delete deno30_y; delete num30_y; delete deno30_pty; delete num30_noweights; delete num30_nominal; delete num30_binned; delete num30_plus1sig; delete num30_min1sig; delete num30_muid_sta; delete num30_muid; delete num30_muid_plus1sig; delete num30_muid_min1sig; delete num30_sta; delete num30_sta_plus1sig; delete num30_sta_min1sig; delete num30_trk_plus1sig; delete num30_trk_min1sig;
  delete deno100_pt; delete num100_pt; delete deno100_y; delete num100_y; delete deno100_pty; delete num100_noweights; delete num100_nominal; delete num100_binned; delete num100_plus1sig; delete num100_min1sig; delete num100_muid_sta; delete num100_muid; delete num100_muid_plus1sig; delete num100_muid_min1sig; delete num100_sta; delete num100_sta_plus1sig; delete num100_sta_min1sig; delete num100_trk_plus1sig; delete num100_trk_min1sig;
}//end of EffStep()



void oniaTree::AccCalc () {

  int nptbins = sizeof(ptbins)/sizeof(double)-1;
  int nybins  = sizeof(ybins)/sizeof(double)-1;
  
  // for 0-10% centrality
  TH1F* deno10_pt = new TH1F ("deno10_pt", "N_{gen} vs p_{T}, 0-10%; p_{T}; N_{total}", nptbins, ptbins); deno10_pt->Sumw2();
  TH1F* num10_pt  = new TH1F ("num10_pt", "N_{reco} vs p_{T}, 0-10%; p_{T}; N_{reco}", nptbins, ptbins); num10_pt->Sumw2();
  TH1F* deno10_y  = new TH1F ("deno10_y","N_{gen} vs y, 0-10%; y; N_{total}", nybins, ybins); deno10_y->Sumw2();
  TH1F* num10_y   = new TH1F ("num10_y","N_{reco} vs y, 0-10%; y; N_{reco}", nybins, ybins); num10_y->Sumw2();

  TH2F* deno10_pty      = new TH2F ("deno10_pty", "N_{gen} vs p_{T} and y, 0-10%; y; p_{T}; N_{total}", nybins, ybins, nptbins, ptbins); deno10_pty->Sumw2();
  TH2F* num10_noweights = new TH2F ("num10_noweights", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_noweights->Sumw2();
  TH2F* num10_nominal   = new TH2F ("num10_nominal", "N_{reco} vs p_{T} and y, 0-10%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num10_nominal->Sumw2();
  

  // for 10-30% centrality
  TH1F* deno30_pt = new TH1F ("deno30_pt", "N_{gen} vs p_{T}, 10-30%; p_{T}; N_{total}", nptbins, ptbins); deno30_pt->Sumw2();
  TH1F* num30_pt  = new TH1F ("num30_pt", "N_{reco} vs p_{T}, 10-30%; p_{T}; N_{reco}", nptbins, ptbins); num30_pt->Sumw2();
  TH1F* deno30_y  = new TH1F ("deno30_y","N_{gen} vs y, 10-30%; y; N_{total}", nybins, ybins); deno30_y->Sumw2();
  TH1F* num30_y   = new TH1F ("num30_y","N_{reco} vs y, 10-30%; y; N_{reco}", nybins, ybins); num30_y->Sumw2();

  TH2F* deno30_pty      = new TH2F ("deno30_pty", "N_{gen} vs p_{T} and y, 10-30%; y; p_{T}; N_{total}", nybins, ybins, nptbins, ptbins); deno30_pty->Sumw2();
  TH2F* num30_noweights = new TH2F ("num30_noweights", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_noweights->Sumw2();
  TH2F* num30_nominal   = new TH2F ("num30_nominal", "N_{reco} vs p_{T} and y, 10-30%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num30_nominal->Sumw2();


  // for 30-100% centrality
  TH1F* deno100_pt = new TH1F ("deno100_pt", "N_{gen} vs p_{T}, 30-100%; p_{T}; N_{total}", nptbins, ptbins); deno100_pt->Sumw2();
  TH1F* num100_pt  = new TH1F ("num100_pt", "N_{reco} vs p_{T}, 30-100%; p_{T}; N_{reco}", nptbins, ptbins); num100_pt->Sumw2();
  TH1F* deno100_y  = new TH1F ("deno100_y","N_{gen} vs y, 30-100%; y; N_{total}", nybins, ybins); deno100_y->Sumw2();
  TH1F* num100_y   = new TH1F ("num100_y","N_{reco} vs y, 30-100%; y; N_{reco}", nybins, ybins); num100_y->Sumw2();

  TH2F* deno100_pty      = new TH2F ("deno100_pty", "N_{gen} vs p_{T} and y, 30-100%; y; p_{T}; N_{total}", nybins, ybins, nptbins, ptbins); deno100_pty->Sumw2();
  TH2F* num100_noweights = new TH2F ("num100_noweights", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_noweights->Sumw2();
  TH2F* num100_nominal   = new TH2F ("num100_nominal", "N_{reco} vs p_{T} and y, 30-100%; y; p_{T}; N_{reco}", nybins, ybins, nptbins, ptbins); num100_nominal->Sumw2();

  
  Long64_t nentries =fChain->GetEntries();
  //nentries = 2000000;
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++)
    {
      if (jentry%10000==0) cout<<"[INFO] "<<jentry*100/nentries<<"% finished"<<'\r'<<flush;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      for (int iQQ=0; iQQ<Gen_QQ_size; iQQ++)
	{
	  TLorentzVector *GenQQ4mom = (TLorentzVector*) Gen_QQ_4mom->At(iQQ);
	  jpsi_m=GenQQ4mom->M();
	  jpsi_pt = GenQQ4mom->Pt();
	  jpsi_rap = GenQQ4mom->Rapidity();

	  if (jpsi_pt < 3 || jpsi_pt > 50) continue;
          if (fabs(jpsi_rap) > 2.4) continue;

	  if (hiBin <= 20) // for 0-10%
	    {
	      deno10_pty->Fill(jpsi_rap, jpsi_pt);
	      deno10_pt->Fill(jpsi_pt);
	      if (jpsi_pt>=6.5) deno10_y->Fill(fabs(jpsi_rap));
	      if (!areGenMuonsInAcceptance2019(iQQ)) continue;
	      num10_noweights->Fill(jpsi_rap, jpsi_pt);
	      num10_nominal->Fill(jpsi_rap, jpsi_pt);
	      num10_pt->Fill(jpsi_pt);
	      if(jpsi_pt >= 6.5) num10_y->Fill(fabs(jpsi_rap));
	      continue;
	    }

	  if (hiBin > 20 && hiBin <= 60) // for 10-30%
	    {
	      deno30_pty->Fill(jpsi_rap, jpsi_pt);
	      deno30_pt->Fill(jpsi_pt);
	      if (jpsi_pt>=6.5) deno30_y->Fill(fabs(jpsi_rap));
	      if (!areGenMuonsInAcceptance2019(iQQ)) continue;
	      num30_noweights->Fill(jpsi_rap, jpsi_pt);
	      num30_nominal->Fill(jpsi_rap, jpsi_pt);
	      num30_pt->Fill(jpsi_pt);
	      if(jpsi_pt >= 6.5) num30_y->Fill(fabs(jpsi_rap));
	      continue;
	    }

	  if (hiBin > 60 && hiBin <= 200) // for 30-100%
	    {
	      deno100_pty->Fill(jpsi_rap, jpsi_pt);
	      deno100_pt->Fill(jpsi_pt);
	      if (jpsi_pt>=6.5) deno100_y->Fill(fabs(jpsi_rap));
	      if (!areGenMuonsInAcceptance2019(iQQ)) continue;
	      num100_noweights->Fill(jpsi_rap, jpsi_pt);
	      num100_nominal->Fill(jpsi_rap, jpsi_pt);
	      num100_pt->Fill(jpsi_pt);
	      if(jpsi_pt >= 6.5) num100_y->Fill(fabs(jpsi_rap));
	      continue;
	    }

	}//end of genQQ loop
    }//end of entries loop

  gSystem->mkdir("FilesAccxEff");
  gSystem->mkdir("FilesAccxEff/Acc");
 
  TFile* fsave = new TFile (Form("FilesAccxEff/Acc/%sAccHists_%s.root", isPr?"pr":"npr", isPbPb?"PbPb":"PP"), "RECREATE");
  
  deno10_pt->Write("deno_0_10_pt"); deno10_y->Write("deno_0_10_y"); deno10_pty->Write("deno_0_10_2d");
  num10_pt->Write("num_0_10_pt"); num10_y->Write("num_0_10_y"); num10_nominal->Write("num_0_10_2d_nominal"); num10_noweights->Write("num_0_10_2d_noweights");
  
  deno30_pt->Write("deno_10_30_pt"); deno30_y->Write("deno_10_30_y"); deno30_pty->Write("deno_10_30_2d");
  num30_pt->Write("num_10_30_pt"); num30_y->Write("num_10_30_y"); num30_nominal->Write("num_10_30_2d_nominal"); num30_noweights->Write("num_10_30_2d_noweights");
  
  deno100_pt->Write("deno_30_100_pt"); deno100_y->Write("deno_30_100_y"); deno100_pty->Write("deno_30_100_2d");
  num100_pt->Write("num_30_100_pt"); num100_y->Write("num_30_100_y"); num100_nominal->Write("num_30_100_2d_nominal"); num100_noweights->Write("num_30_100_2d_noweights");
  
  fsave->Close();
  
  delete fsave;
  delete deno10_pt; delete num10_pt; delete deno10_y; delete num10_y; delete deno10_pty; delete num10_noweights; delete num10_nominal;
  delete deno30_pt; delete num30_pt; delete deno30_y; delete num30_y; delete deno30_pty; delete num30_noweights; delete num30_nominal;
  delete deno100_pt; delete num100_pt; delete deno100_y; delete num100_y; delete deno100_pty; delete num100_noweights; delete num100_nominal;

}//end of AccCalc function



void oniaTree::ClosureTest()
{
  gStyle->SetOptStat(0);
  Double_t etabins []={0, 1.6, 2.4};
  TH1F* mixCount = new TH1F ("mixCount", "y distribution at reco level with mixAccEff", 2, etabins);
  TH1F* genCount = new TH1F ("genCount", "y distribution at gen level", 2, etabins);
  TH1F* sepCount = new TH1F ("sepCount", "y distribution at reco level with separate AccEff", 2, etabins);
  TFile* prf (0x0);
  TFile* nprf (0x0);
  prf = TFile::Open("Utilities/pr_correction_AccEff.root","READ");
  nprf =  TFile::Open("Utilities/npr_correction_AccEff.root","READ");

  TEfficiency* prEff = (TEfficiency*) prf->Get("hcorr_Jpsi_PP");
  TEfficiency* nprEff = (TEfficiency*) nprf->Get("hcorr_Jpsi_PP");

  Long64_t nentries = fChain->GetEntries();
  //nentries = 10000000;
  Long64_t nbytes = 0, nb = 0;

  TF1  *bfrac = new TF1("bfrac","exp(-2.74079+0.211476*pow(x,1)-0.007024*pow(x,2)+(7.90067e-05)*pow(x,3))", 3, 50);
  double bf =1.0; double prW = 1.0; double nprW = 1.0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) 
    {
      if (jentry%1000000==0) cout<<"[INFO] processing entry "<<jentry<<"/"<<nentries<<endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      for (int iQQ=0; iQQ<Gen_QQ_size; iQQ++)
	{
	  TLorentzVector *GenQQ4mom = (TLorentzVector*) Gen_QQ_4mom->At(iQQ);
	  jpsi_m = GenQQ4mom->M();
	  jpsi_pt = GenQQ4mom->Pt();
	  jpsi_rap = GenQQ4mom->Rapidity();
	  
	  if (jpsi_pt>6.5 && jpsi_pt<35 && fabs(jpsi_rap)<2.4 && jpsi_m>2.6 && jpsi_m<3.5)
	    genCount->Fill(jpsi_rap);
	}
	  for (int iQQ=0; iQQ<Reco_QQ_size; iQQ++) 
	    {
	      TLorentzVector *RecoQQ4mom = (TLorentzVector*) Reco_QQ_4mom->At(iQQ);
	      jpsi_pt = RecoQQ4mom->Pt();
	      jpsi_rap = RecoQQ4mom->Rapidity();
	      jpsi_m = RecoQQ4mom->M();
	      bf = bfrac->Eval(jpsi_pt);
	      if (
		  jpsi_pt > 6.5  && jpsi_pt<35 &&
		  (areMuonsInAcceptance2019(iQQ))&&  // 2019 Global Muon Acceptance Cuts
		  (passQualityCuts2019(iQQ)) &&  // 2019 Soft Global Muon Quality Cuts
		  (isTriggerMatch(iQQ, triggerIndex_PP)) &&// if it matches the trigger 
		  (Reco_QQ_whichGen[iQQ]!=-1)
		  )
		{
		  if (Reco_QQ_sign[iQQ]==0 && fabs(jpsi_rap)<2.4 && jpsi_m>2.6 && jpsi_m<3.5) 
		    {
		      prW = (prEff->GetEfficiency(prEff->FindFixBin(jpsi_rap,jpsi_pt)));
		      nprW = (nprEff->GetEfficiency(nprEff->FindFixBin(jpsi_rap,jpsi_pt)));
		      weight = 1.0/(bf*nprW + (1-bf)*prW);
		      
		      mixCount->Fill(jpsi_rap, weight);
		      if (isPr) weight = 1.0/prW;
		      else weight = 1.0/nprW;
		      sepCount->Fill(jpsi_rap, weight);
		    }
		}
	    }
    }
  TFile* testfile (0x0);
  if (isPr)
	testfile = new TFile ("RatioStudy/prClosureTest.root","RECREATE");
  else
    testfile = new TFile ("RatioStudy/nprClosureTest.root","RECREATE");
  genCount->Write("genYields");
  mixCount->Write("mixAccEffYields");
  sepCount->Write("sepAccEffYields");
  testfile->Close();
  
  genCount->SetLineColor(kRed);
  genCount->SetLineWidth(2);
  mixCount->SetLineColor(kBlue);
  mixCount->SetLineWidth(1);
  sepCount->SetLineColor(kGreen+2);
  sepCount->SetLineWidth(1);
  sepCount->SetLineStyle(2);
  genCount->SetTitle(Form("%s Comparison", isPr?"prompt":"nonprompt"));
  TCanvas* c = new TCanvas("c","", 1000, 1000);
  genCount->Draw();
  mixCount->Draw("same");
  sepCount->Draw("same");
  TLegend* leg = new TLegend (0.1, 0.75, 0.25, 0.9);
  leg->AddEntry(genCount, "N_{gen}","lep");
  leg->AddEntry(mixCount, "N_{reco}^{mix AccEff}","lep");
  leg->AddEntry(sepCount, "N_{reco}^{sep AccEff}","lep");
  leg->SetBorderSize(0);
  leg->Draw("same");
  c->SaveAs(Form("RatioStudy/%sGenRecoComparison.root",isPr?"pr":"npr"));
}

void oniaTree::Plot() {cout << "[INFO] This function is empty at the moment. It can be used to make nice plots for the analysis notes"<< endl;}
