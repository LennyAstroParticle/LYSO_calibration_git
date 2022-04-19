

void LYSO_FINAL_COMPARISON(){

  TFile * PLOT_FILE = new TFile("PLOT_LYSO.root","UPDATE");
  gStyle->SetOptStat(0);

  //MIP//
  TH2D* LYSO_0_R= (TH2D*)PLOT_FILE->Get("LYSO_0_MIP_LYSO_TIFPA_R");TH2D* LYSO_0_L= (TH2D*)PLOT_FILE->Get("LYSO_0_MIP_LYSO_TIFPA_L");LYSO_0_L->SetTitle("L_LYSO0");LYSO_0_R->SetTitle("R_LYSO0");
  TH2D* LYSO_1_R= (TH2D*)PLOT_FILE->Get("LYSO_1_MIP_LYSO_TIFPA_R");TH2D* LYSO_1_L= (TH2D*)PLOT_FILE->Get("LYSO_1_MIP_LYSO_TIFPA_L");LYSO_1_L->SetTitle("L_LYSO1");LYSO_1_R->SetTitle("R_LYSO1");
  TH2D* LYSO_2_R= (TH2D*)PLOT_FILE->Get("LYSO_2_MIP_LYSO_TIFPA_R");TH2D* LYSO_2_L= (TH2D*)PLOT_FILE->Get("LYSO_2_MIP_LYSO_TIFPA_L");LYSO_2_L->SetTitle("L_LYSO2");LYSO_2_R->SetTitle("R_LYSO2");
  TH2D* LYSO_3_R= (TH2D*)PLOT_FILE->Get("LYSO_3_MIP_LYSO_TIFPA_R");TH2D* LYSO_3_L= (TH2D*)PLOT_FILE->Get("LYSO_3_MIP_LYSO_TIFPA_L");LYSO_3_L->SetTitle("L_LYSO3");LYSO_3_R->SetTitle("R_LYSO3");
  TH2D* LYSO_5_R= (TH2D*)PLOT_FILE->Get("LYSO_5_MIP_LYSO_TIFPA_R");TH2D* LYSO_5_L= (TH2D*)PLOT_FILE->Get("LYSO_5_MIP_LYSO_TIFPA_L");LYSO_5_L->SetTitle("L_LYSO5");LYSO_5_R->SetTitle("R_LYSO5");
  TH2D* LYSO_6_R= (TH2D*)PLOT_FILE->Get("LYSO_6_MIP_LYSO_TIFPA_R");TH2D* LYSO_6_L= (TH2D*)PLOT_FILE->Get("LYSO_6_MIP_LYSO_TIFPA_L");LYSO_6_L->SetTitle("L_LYSO6");LYSO_6_R->SetTitle("R_LYSO6");

  //ERRORI//
  TH2D* Err_LYSO_0_R= (TH2D*)PLOT_FILE->Get("LYSO_0_MIP_Err_LYSO_TIFPA_R");Err_LYSO_0_R->SetTitle("Err_L_LYSO0");TH2D* Err_LYSO_0_L= (TH2D*)PLOT_FILE->Get("LYSO_0_MIP_Err_LYSO_TIFPA_L");Err_LYSO_0_L->SetTitle("Err_L_LYSO0");
  TH2D* Err_LYSO_1_R= (TH2D*)PLOT_FILE->Get("LYSO_1_MIP_Err_LYSO_TIFPA_R");Err_LYSO_1_R->SetTitle("Err_L_LYSO0");TH2D* Err_LYSO_1_L= (TH2D*)PLOT_FILE->Get("LYSO_1_MIP_Err_LYSO_TIFPA_L");Err_LYSO_1_L->SetTitle("Err_L_LYSO1");
  TH2D* Err_LYSO_2_R= (TH2D*)PLOT_FILE->Get("LYSO_2_MIP_Err_LYSO_TIFPA_R");Err_LYSO_2_R->SetTitle("Err_L_LYSO0");TH2D* Err_LYSO_2_L= (TH2D*)PLOT_FILE->Get("LYSO_2_MIP_Err_LYSO_TIFPA_L");Err_LYSO_2_L->SetTitle("Err_L_LYSO2");
  TH2D* Err_LYSO_3_R= (TH2D*)PLOT_FILE->Get("LYSO_3_MIP_Err_LYSO_TIFPA_R");Err_LYSO_3_R->SetTitle("Err_L_LYSO0");TH2D* Err_LYSO_3_L= (TH2D*)PLOT_FILE->Get("LYSO_3_MIP_Err_LYSO_TIFPA_L");Err_LYSO_3_L->SetTitle("Err_L_LYSO3");
  TH2D* Err_LYSO_5_R= (TH2D*)PLOT_FILE->Get("LYSO_5_MIP_Err_LYSO_TIFPA_R");Err_LYSO_5_R->SetTitle("Err_L_LYSO0");TH2D* Err_LYSO_5_L= (TH2D*)PLOT_FILE->Get("LYSO_5_MIP_Err_LYSO_TIFPA_L");Err_LYSO_5_L->SetTitle("Err_L_LYSO5");
  TH2D* Err_LYSO_6_R= (TH2D*)PLOT_FILE->Get("LYSO_6_MIP_Err_LYSO_TIFPA_R");Err_LYSO_6_R->SetTitle("Err_L_LYSO0");TH2D* Err_LYSO_6_L= (TH2D*)PLOT_FILE->Get("LYSO_6_MIP_Err_LYSO_TIFPA_L");Err_LYSO_6_L->SetTitle("Err_L_LYSO6");

  //GRAFICI//
  TCanvas * c0 = new TCanvas();c0->Divide(1,6);
  c0->cd(1);LYSO_0_L->Draw("COLZ");LYSO_0_L->Draw("TEXT SAME");
  c0->cd(2);LYSO_1_L->Draw("COLZ");LYSO_1_L->Draw("TEXT SAME");
  c0->cd(3);LYSO_2_L->Draw("COLZ");LYSO_2_L->Draw("TEXT SAME");
  c0->cd(4);LYSO_3_L->Draw("COLZ");LYSO_3_L->Draw("TEXT SAME");
  c0->cd(5);LYSO_5_L->Draw("COLZ");LYSO_5_L->Draw("TEXT SAME");
  c0->cd(6);LYSO_6_L->Draw("COLZ");LYSO_6_L->Draw("TEXT SAME");
  TCanvas * c00 = new TCanvas();c00->Divide(1,6);
  c00->cd(1);LYSO_0_R->Draw("COLZ");LYSO_0_R->Draw("TEXT SAME");
  c00->cd(2);LYSO_1_R->Draw("COLZ");LYSO_1_R->Draw("TEXT SAME");
  c00->cd(3);LYSO_2_R->Draw("COLZ");LYSO_2_R->Draw("TEXT SAME");
  c00->cd(4);LYSO_3_R->Draw("COLZ");LYSO_3_R->Draw("TEXT SAME");
  c00->cd(5);LYSO_5_R->Draw("COLZ");LYSO_5_R->Draw("TEXT SAME");
  c00->cd(6);LYSO_6_R->Draw("COLZ");LYSO_6_R->Draw("TEXT SAME");

  TCanvas * c000 = new TCanvas();
  LYSO_3_L->Draw("COLZ");LYSO_3_L->Draw("TEXT SAME");
  TCanvas * c0000 = new TCanvas();
  LYSO_3_R->Draw("COLZ");LYSO_3_R->Draw("TEXT SAME");

  TCanvas * c1 = new TCanvas();c1->Divide(2,6);
  c1->cd(1);Err_LYSO_0_L->Draw("COLZ");Err_LYSO_0_L->Draw("TEXT SAME");
  c1->cd(3);Err_LYSO_1_L->Draw("COLZ");Err_LYSO_1_L->Draw("TEXT SAME");
  c1->cd(5);Err_LYSO_2_L->Draw("COLZ");Err_LYSO_2_L->Draw("TEXT SAME");
  c1->cd(7);Err_LYSO_3_L->Draw("COLZ");Err_LYSO_3_L->Draw("TEXT SAME");
  c1->cd(9);Err_LYSO_5_L->Draw("COLZ");Err_LYSO_5_L->Draw("TEXT SAME");
  c1->cd(11);Err_LYSO_6_L->Draw("COLZ");Err_LYSO_6_L->Draw("TEXT SAME");

  c1->cd(2);Err_LYSO_0_R->Draw("COLZ");Err_LYSO_0_R->Draw("TEXT SAME");
  c1->cd(4);Err_LYSO_1_R->Draw("COLZ");Err_LYSO_1_R->Draw("TEXT SAME");
  c1->cd(6);Err_LYSO_2_R->Draw("COLZ");Err_LYSO_2_R->Draw("TEXT SAME");
  c1->cd(8);Err_LYSO_3_R->Draw("COLZ");Err_LYSO_3_R->Draw("TEXT SAME");
  c1->cd(10);Err_LYSO_5_R->Draw("COLZ");Err_LYSO_5_R->Draw("TEXT SAME");
  c1->cd(12);Err_LYSO_6_R->Draw("COLZ");Err_LYSO_6_R->Draw("TEXT SAME");

  double ErrMaxL[6]={Err_LYSO_0_L->GetMaximum(),Err_LYSO_1_L->GetMaximum(),Err_LYSO_2_L->GetMaximum(),Err_LYSO_3_L->GetMaximum(),Err_LYSO_5_L->GetMaximum(),Err_LYSO_6_L->GetMaximum()};
  double ErrMinL[6]={Err_LYSO_0_L->GetMinimum(),Err_LYSO_1_L->GetMinimum(),Err_LYSO_2_L->GetMinimum(),Err_LYSO_3_L->GetMinimum(),Err_LYSO_5_L->GetMinimum(),Err_LYSO_6_L->GetMinimum()};

  double ErrMaxR[6]={Err_LYSO_0_R->GetMaximum(),Err_LYSO_1_R->GetMaximum(),Err_LYSO_2_R->GetMaximum(),Err_LYSO_3_R->GetMaximum(),Err_LYSO_5_R->GetMaximum(),Err_LYSO_6_R->GetMaximum()};
  double ErrMinR[6]={Err_LYSO_0_R->GetMinimum(),Err_LYSO_1_R->GetMinimum(),Err_LYSO_2_R->GetMinimum(),Err_LYSO_3_R->GetMinimum(),Err_LYSO_5_R->GetMinimum(),Err_LYSO_6_R->GetMinimum()};

  double LYSO_index[6]={0,1,2,3,5,6};
  double MeanErr[4];
  double ErrMeanErr[4];
  auto ErrMaxGrL = new TGraph(6,LYSO_index,ErrMaxL);ErrMaxGrL->SetTitle("ErrMaxL");ErrMaxGrL->Fit("pol0");MeanErr[0]=ErrMaxGrL->GetFunction("pol0")->GetParameter(0);ErrMeanErr[0]=ErrMaxGrL->GetFunction("pol0")->GetParError(0);ErrMaxGrL->GetXaxis()->SetTitle("LYSO#");ErrMaxGrL->GetYaxis()->SetTitle("Error [V]");
  auto ErrMaxGrR = new TGraph(6,LYSO_index,ErrMaxR);ErrMaxGrR->SetTitle("ErrMaxR");ErrMaxGrR->Fit("pol0");MeanErr[1]=ErrMaxGrR->GetFunction("pol0")->GetParameter(0);ErrMeanErr[1]=ErrMaxGrR->GetFunction("pol0")->GetParError(0);ErrMaxGrR->GetXaxis()->SetTitle("LYSO#");ErrMaxGrR->GetYaxis()->SetTitle("Error [V]");
  auto ErrMinGrL = new TGraph(6,LYSO_index,ErrMinL);ErrMinGrL->SetTitle("ErrMinL");ErrMinGrL->Fit("pol0");MeanErr[2]=ErrMinGrL->GetFunction("pol0")->GetParameter(0);ErrMeanErr[2]=ErrMinGrL->GetFunction("pol0")->GetParError(0);ErrMinGrL->GetXaxis()->SetTitle("LYSO#");ErrMinGrL->GetYaxis()->SetTitle("Error [V]");
  auto ErrMinGrR = new TGraph(6,LYSO_index,ErrMinR);ErrMinGrR->SetTitle("ErrMinR");ErrMinGrR->Fit("pol0");MeanErr[3]=ErrMinGrR->GetFunction("pol0")->GetParameter(0);ErrMeanErr[3]=ErrMinGrR->GetFunction("pol0")->GetParError(0);ErrMinGrR->GetXaxis()->SetTitle("LYSO#");ErrMinGrR->GetYaxis()->SetTitle("Error [V]");

  cout<<"ErrMaxL = "<< MeanErr[0]<< " +- "<< ErrMeanErr[0]<<endl;
  cout<<"ErrMaxR = "<< MeanErr[1]<< " +- "<< ErrMeanErr[1]<<endl;
  cout<<"ErrMinL = "<< MeanErr[2]<< " +- "<< ErrMeanErr[2]<<endl;
  cout<<"ErrMinR = "<< MeanErr[3]<< " +- "<< ErrMeanErr[3]<<endl;


  TCanvas* errC = new TCanvas();
  errC->Divide(2,2);

  errC->cd(2);
  ErrMaxGrR->Draw("al*");
  gPad->SetLogy();
  errC->cd(1);
  ErrMaxGrL->Draw("al*");
  gPad->SetLogy();
  errC->cd(3);
  ErrMinGrL->Draw("al*");
  gPad->SetLogy();
  errC->cd(4);
  ErrMinGrR->Draw("al*");
  gPad->SetLogy();

  //MAPPA MEDIA MIP L//
  double bin_x=LYSO_0_L->GetNbinsX();
  double bin_y=LYSO_0_L->GetNbinsY();
  TH2D *hmeanL = new TH2D("hmeanL","L_mean_MAP:MPV(X,Y);X[mm];Y[mm];MPV(X,Y)",bin_x,0,150,bin_y,0,50);//questo histo definisce il binning delle MIP
  double nx=LYSO_0_L->GetNbinsX();
  double ny=LYSO_0_L->GetNbinsY();
  for(int j=1;j<=ny;j++){
      for(int i=1;i<=nx;i++){
         hmeanL->SetBinContent(i,j,0.16666666667*(LYSO_0_L->GetBinContent(i,j)+LYSO_1_L->GetBinContent(i,j)+LYSO_2_L->GetBinContent(i,j)+LYSO_3_L->GetBinContent(i,j)+LYSO_5_L->GetBinContent(i,j)+LYSO_6_L->GetBinContent(i,j)+0.16666666667*(LYSO_0_R->GetBinContent(nx+1-i,ny+1-j)+LYSO_1_R->GetBinContent(nx+1-i,ny+1-j)+LYSO_2_R->GetBinContent(nx+1-i,ny+1-j)+LYSO_3_R->GetBinContent(nx+1-i,ny+1-j)+LYSO_5_R->GetBinContent(nx+1-i,ny+1-j)+LYSO_6_R->GetBinContent(nx+1-i,ny+1-j)  )));
         hmeanL->SetBinError(i,j,0.16666666667*(LYSO_0_L->GetBinError(i,j)+LYSO_1_L->GetBinError(i,j)+LYSO_2_L->GetBinError(i,j)+LYSO_3_L->GetBinError(i,j)+LYSO_5_L->GetBinError(i,j)+LYSO_6_L->GetBinError(i,j)  ));
      }
   }
  //MAPPA MEDIA MIP R//
  TH2D *hmeanR = new TH2D("hmeanR","R_mean_MAP:MPV(X,Y);X[mm];Y[mm];MPV(X,Y)",bin_x,0,150,bin_y,0,50);//questo histo definisce il binning delle MIP
  for(int j=1;j<=ny;j++){
      for(int i=1;i<=nx;i++){
         hmeanR->SetBinContent(i,j,0.16666666667*(LYSO_0_R->GetBinContent(i,j)+LYSO_1_R->GetBinContent(i,j)+LYSO_2_R->GetBinContent(i,j)+LYSO_3_R->GetBinContent(i,j)+LYSO_5_R->GetBinContent(i,j)+LYSO_6_R->GetBinContent(i,j) +0.16666666667*(LYSO_0_L->GetBinContent(nx+1-i,ny+1-j)+LYSO_1_L->GetBinContent(nx+1-i,ny+1-j)+LYSO_2_L->GetBinContent(nx+1-i,ny+1-j)+LYSO_3_L->GetBinContent(nx+1-i,ny+1-j)+LYSO_5_L->GetBinContent(nx+1-i,ny+1-j)+LYSO_6_L->GetBinContent(nx+1-i,ny+1-j)  )));
         hmeanR->SetBinError(i,j,0.16666666667*(LYSO_0_R->GetBinError(i,j)+LYSO_1_R->GetBinError(i,j)+LYSO_2_R->GetBinError(i,j)+LYSO_3_R->GetBinError(i,j)+LYSO_5_R->GetBinError(i,j)+LYSO_6_R->GetBinError(i,j)  ));
      }
   }

  TCanvas * cm = new TCanvas();
  cm->Divide(1,2);
  cm->cd(1);
  hmeanL->Draw("COLZ");
  hmeanL->Draw("TEXT SAME");
  cm->cd(2);
  hmeanR->Draw("COLZ");
  hmeanR->Draw("TEXT SAME");


  //fare ora i grafici di ogni mappa diviso il valore centrale della mappa media per vedere di quanto si discostano-> questo sarà il mio indice finale.
  //definire quindi una feature che mi dice di quanto è macchiato
  //fare vari test con i parametri di fitting per vedere quando viene meglio.
  //mettere magari i parametri del fit come argomento della funzione MIPVIEW e fare la stessa analisi con parametri diversi per osservare come cambia l'errore.
  //fare una sorta di gradient descent sui parametri finali per tunare l'algoritmo.
  
return;
}
