
///// ANALISI DEI DATI TORRETTA + LYSO -> 01/02 2022 scritta

TFile * PLOT_LYSO = new TFile("PLOT_LYSO.root","UPDATE");
TF1* f1;   // funzione che si occupa di fare i fit sulle distribuzioni LANDAU, metto f1 globale quindi tutti sanno chi è
double fMPV_TRK(double xc, double yc, double x_width, double y_width, TTree* tree1ALL, TString PMT = "R", double Bins=20, double VMin=0.015, double VMax=0.4);
void plotting(TTree* tree1ALL,TString PMT, int N_LYSO=1, double bins=20,double VMin=0.014,double VMax=0.4,double bin_x=15, double bin_y=5);
void MIPVIEWNEW_TRK(TString Fname="../../DST/MIP8.dst",int N_LYSO=1,double Ksigma=1,double bins=20,double VMin=0.014,double VMax=0.4,double bin_x=15,double bin_y=5);

bool centr_norm=false;
double verbose=true;

void MIPVIEWNEW_TRK_ALL(){
//FILE,N_LYSO,KSigma,Bins,VMim,VMax//

double KSigma=1.5;
double bins=30;
double VMin=0.014;
double VMax=0.6;
double bin_x=7;
double bin_y=3;
MIPVIEWNEW_TRK("LYSO0_TRLT2",0,KSigma,bins,VMin,VMax,bin_x,bin_y);
MIPVIEWNEW_TRK("LYSO1_TRLT2",1,KSigma,bins,VMin,VMax,bin_x,bin_y);//aggiunge anche il 3
MIPVIEWNEW_TRK("LYSO2_TRLT2",2,KSigma,bins,VMin,VMax,bin_x,bin_y);
MIPVIEWNEW_TRK("LYSO3_TRLT0",3,KSigma,bins,VMin,VMax,bin_x,bin_y);
MIPVIEWNEW_TRK("LYSO5_TRLT2",5,KSigma,bins,VMin,VMax,bin_x,bin_y);
MIPVIEWNEW_TRK("LYSO6_TRLT0",6,KSigma,bins,VMin,VMax,bin_x,bin_y);
}


void MIPVIEWNEW_TRK(TString Fname="../../DST/MIP8.dst",int N_LYSO=1,double Ksigma=1,double bins=20,double VMin=0.014,double VMax=0.4,double bin_x,double bin_y){

TTree* tree1ALL= new TTree();
TTree* tree2ALL= new TTree();

//________________________LEGGI DATI OSC_________________________________________________//
TTree* treeOSC = new TTree("tree1","data from ascii file");
treeOSC->ReadFile(Form("../LYSO%i/DST/%s.dst",N_LYSO,Fname.Data()),"event/I:pkpkL/F:pkpkR/F:areaL/F:areaR/F:DTLR/F:areaU/F:DTLU/F:areaD/F:DTLD/F:pkpkU/F:pkpkD/F:DTRD/F");

//________________________LEGGI DATI TORR_________________________________________________//
TTree* treeTORR = new TTree("tree2","tree2");
treeTORR->ReadFile(Form("../LYSO%i/TXT/%s.txt",N_LYSO,Fname.Data()),"event_trk/I:dirX/F:dirY/F:dirZ/F:X0/F:Y0/F:Z0/F");                                                                     

if(N_LYSO==1){
//________________________LEGGI DATI OSC_________________________________________________//
  TTree* treeOSC2 = new TTree("tree1","data from ascii file");
  treeOSC2->ReadFile(Form("../LYSO%i/DST/%s.dst",N_LYSO,"LYSO1_TRLT3"),"event/I:pkpkL/F:pkpkR/F:areaL/F:areaR/F:DTLR/F:areaU/F:DTLU/F:areaD/F:DTLD/F:pkpkU/F:pkpkD/F:DTRD/F");

//________________________LEGGI DATI TORR_________________________________________________//
  TTree* treeTORR2 = new TTree("tree2","tree2");
  treeTORR2->ReadFile(Form("../LYSO%i/TXT/%s.txt",N_LYSO,"LYSO1_TRLT3"),"event_trk/I:dirX/F:dirY/F:dirZ/F:X0/F:Y0/F:Z0/F");                                                                     

  TList* list1 = new TList();
  list1->Add(treeOSC);
  list1->Add(treeOSC2);

  TList* list2 = new TList();
  list2->Add(treeTORR);
  list2->Add(treeTORR2);

  tree1ALL = TTree::MergeTrees(list1);
  tree2ALL = TTree::MergeTrees(list2);
  tree1ALL->AddFriend(tree2ALL);
};

if(N_LYSO!=1){
  tree1ALL = treeOSC;
  tree2ALL = treeTORR;
  tree1ALL->AddFriend(tree2ALL);
}


 if(N_LYSO==0){
tree1ALL->SetAlias("X_LYSO","X0+(65-Z0)*dirX/dirZ+10");
tree1ALL->SetAlias("Y_LYSO","Y0+(65-Z0)*dirY/dirZ+10");
};

 if(N_LYSO==1){
tree1ALL->SetAlias("X_LYSO","X0+(60-Z0)*dirX/dirZ");
tree1ALL->SetAlias("Y_LYSO","Y0+(60-Z0)*dirY/dirZ+10");
};

 if(N_LYSO==2||N_LYSO==3){
tree1ALL->SetAlias("X_LYSO","X0+(60-Z0)*dirX/dirZ+5");
tree1ALL->SetAlias("Y_LYSO","Y0+(60-Z0)*dirY/dirZ+10");
};

 if(N_LYSO==5||N_LYSO==6){
tree1ALL->SetAlias("X_LYSO","X0+(60-Z0)*dirX/dirZ-5");
tree1ALL->SetAlias("Y_LYSO","Y0+(60-Z0)*dirY/dirZ+10");
};


//plot della posizione di incidenza del muone riportata sulla posizione della faccia superiore del LYSO
TCanvas* c100 = new TCanvas();
TH2D* hLYSO = new TH2D(Form("hLYSO_%i",N_LYSO),";X[mm];Y[mm];counts[#]",50,-10,160,20,-25,75);
gStyle->SetOptStat(1);
tree1ALL->Draw("Y_LYSO:X_LYSO>>hLYSO","dirZ>0&&pkpkR<1.4&&pkpkL<1.4&&abs(DTLR)<6e-9&&DTLR!=0","COLZ"); // le tracce che non hanno attraversato tutto il tracciatore hanno dirZ=-999
gPad->SetGrid();
hLYSO->Write("LYSO_TIFPA");


//qui definisco effettivamente la funzione che viene usata dentro a plotting, dentro a plotting chiamo fMPV_TRK per ogni pixel che valuto
//double Ksigma = 1;
f1 = new TF1("f1",Form("abs([0]*(x<([2]-%f*[3])))+landau(1)",Ksigma),0,1);

//effettuo l'analisi per il PMT L e il PMT R
plotting(tree1ALL,"L",N_LYSO,bins,VMin,VMax,bin_x,bin_y);
plotting(tree1ALL,"R",N_LYSO,bins,VMin,VMax,bin_x,bin_y);

if(verbose==true){delete c100;};
}


//___________________FUNZIONE CHE SI OCCUPA DI ANALIZZARE LE MIP NELLA SINGOLA REGIONE E DI FARE LA RETTA DI CALIBRAZIONE mV ENERGIA________
void plotting(TTree* tree1ALL,TString PMT, int N_LYSO, double bins,double VMin,double VMax,double bin_x, double bin_y){
//qui mi occupo di valutare la MIP nell'area selezionata, chiamo la funzione fMPV_TRK dentro ad ogni area della superficie del LYSO che considero

TTree* treeMPV = new TTree();
double X_center;
double Y_center;
double MPV;
double MPV_center;
double X_center_c;
double Y_center_c;
double X_W_center, Y_W_center;

//tree che prende tutti i valori di MPV che trovo, non utilizzato 
treeMPV->Branch("X_center", &X_center, "X_center/D");
treeMPV->Branch("X_center", &Y_center, "Y_center/D");
treeMPV->Branch("MPV", &MPV, "MPV/D");

//unità = mm
TH2D *hMPV = new TH2D("hMPV",Form("LYSO_%i->PMT_%s:MPV(X,Y);X[mm];Y[mm];MPV(X,Y)",N_LYSO,PMT.Data()),bin_x,0,150,bin_y,0,50);//questo histo definisce il binning delle MIP
TH2D *hErr = new TH2D("hMPVErr",Form("ERROR_PMT_%s:MPV(X,Y);X[mm];Y[mm];MPV(X,Y)",PMT.Data()),bin_x,0,150,bin_y,0,50);//questo histo definisce il binning delle MIP
TH2D *hEntr = new TH2D("hMPVEntr",Form("ENTRIES_PMT_%s:MPV(X,Y);X[mm];Y[mm];MPV(X,Y)",PMT.Data()),bin_x,0,150,bin_y,0,50);//questo histo definisce il binning delle MIP

//prendo il bin centrale (area al centro della sup del LYSO)
TCanvas* c500 = new TCanvas();
X_center_c = hMPV->GetXaxis()->GetBinCenter(hMPV->GetNbinsX()/2+1);
Y_center_c = hMPV->GetYaxis()->GetBinCenter(hMPV->GetNbinsY()/2+1);
X_W_center = hMPV->GetXaxis()->GetBinWidth(hMPV->GetNbinsX()/2+1)/2;
Y_W_center = hMPV->GetYaxis()->GetBinWidth(hMPV->GetNbinsY()/2+1)/2;
fMPV_TRK(X_center_c,Y_center_c,X_W_center,Y_W_center,tree1ALL,PMT.Data());
MPV_center = f1->GetParameter(2);

delete c500;
double MPV_rapp;
double X_W,Y_W;

if (centr_norm==false){
MPV_center=1;
}
//itero su tutti i bin che voglio fare e riempio gli istogrammi con i valori relativi all'area selezionata
TCanvas *ctot = new TCanvas();
ctot->Divide(hMPV->GetNbinsX(),hMPV->GetNbinsY());
int k=0;
for(int j=1;j<=hMPV->GetNbinsY();j++){
  if(j!=1){k+=hMPV->GetNbinsX()-1;};
  for(int i=1;i<=hMPV->GetNbinsX();i++){
    X_center = hMPV->GetXaxis()->GetBinCenter(i);
    Y_center = hMPV->GetYaxis()->GetBinCenter(j);
    X_W = (hMPV->GetXaxis()->GetBinWidth(i))/2;
    Y_W = (hMPV->GetYaxis()->GetBinWidth(j))/2;
    ctot->cd((hMPV->GetNbinsX()*hMPV->GetNbinsY()-j*hMPV->GetNbinsX())+(i));
    hEntr->SetBinContent(i,j,fMPV_TRK(X_center,Y_center,X_W,Y_W,tree1ALL,PMT.Data(),bins,VMin,VMax));
    MPV = f1->GetParameter(2);
    treeMPV->Fill();
    MPV_rapp=MPV/MPV_center;
    hMPV->SetBinContent(i,j,MPV_rapp);
    hErr->SetBinContent(i,j,f1->GetParError(2)/MPV_center);
    hMPV->SetBinError(i,j,f1->GetParError(2)/MPV_center);
  }
}

gStyle->SetOptStat(0);
hMPV->Write(Form("LYSO_%i_MIP_LYSO_TIFPA_%s",N_LYSO,PMT.Data()));
hErr->Write(Form("LYSO_%i_MIP_Err_LYSO_TIFPA_%s",N_LYSO,PMT.Data()));
hEntr->Write(Form("LYSO_%i_MIP_Entr_LYSO_TIFPA_%s",N_LYSO,PMT.Data()));

if(verbose==true){delete ctot;};

TCanvas *c2 = new TCanvas();
c2->Divide(1,3);
c2->cd(1);
hMPV->Draw("COLZ");
hMPV->Draw("TEXTE SAME");
c2->cd(2);
hErr->Draw("COLZ");
hErr->Draw("TEXT SAME");
c2->cd(3);
hEntr->Draw("COLZ");
hEntr->Draw("TEXT SAME");

if(verbose==true){delete c2;};

PLOT_LYSO->Write();
return;
}


//___________FUNZIONE CHE FA IL FIT DELLA MIP NELLA REGIONE INDICATA__________________________________________________________

double fMPV_TRK(double xc, double yc, double x_width, double y_width, TTree* tree1ALL, TString PMT = "R", double Bins, double VMin=0.015,double VMax=0.4 ){

  //__________________________FUNZIONE DI FIT LANDAU______________________________________________//

  //definisco l'istogramma che si occupa dei valori di MIP, prende come argomento il centro dell'area che considero e la largezza di esso 
  TH1D* htmp2 = new TH1D("htmp2",Form("%s_MIP(%.2f,%.2f);Amplitude*Cos(#theta) [V];LYSO counts [#]",PMT.Data(),xc,yc),Bins,VMin,VMax);
  tree1ALL->Draw(Form("pkpk%s*dirZ>>htmp2",PMT.Data()),Form("dirZ>0&&pkpkR<1.4&&pkpkL<1.4&&abs(DTLR)<6e-9&&abs(X_LYSO-%f)<%f&&abs(Y_LYSO-%f)<%f",xc,x_width,yc,y_width),"colz");

  //setting dei parametri
  f1->SetParameter(1,float(htmp2->GetEntries())*0.5);
  f1->SetParameter(2,htmp2->GetMean());
  f1->SetParameter(0,1);
  f1->FixParameter(4,0);
  //f1->FixParameter(0,0);


  // questa condizione è per il pixel rotto
  if(xc>125&&yc>40){
  f1->FixParameter(3,f1->GetParameter(3));  
  }
  else{
  f1->ReleaseParameter(3);
  f1->SetParameter(3,(1./4.)*htmp2->GetStdDev());
  }
  htmp2->Fit("f1","L","",VMin,VMax);
  htmp2->Fit("f1","L","",VMin,VMax);
  htmp2->Draw("");

  //delete c1;    
  return htmp2->GetEntries();                                                        
}

