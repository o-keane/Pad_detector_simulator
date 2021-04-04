{
 TF1 *neff=new TF1("neff","[0]",0,1000);
 neff->SetParameter(0,1);
 KPad det(7000,300);
 det->Neff=neff;
 det->Voltage=0;
 det->SetUpVolume(1);
 det->SetUpElectrodes();

 det.SetDebug(0);
 det.CalField(0);
 det.CalField(1);
 
 Tcanvas c5:
 det->SetEntryPoint(10, 50, 0.5);
 det->SetExitPoint(7800,50,0.5);
 det->diff=1;
 det->ShowMipIR(100);
 
 TCanvas c1;
 c1.cd();
 c1.SetTitle("Electric Field");
 det.Draw("EFxy").Draw("COLZ");	//Draw("EFxy", 60) for z=60um
 
 TCanvas c2;
 c2.cd();
 c2.SetTitle("Electric Potential");
 det.Draw("EP").Draw("COLZ");
 
 //TCanvas c3;
 //c3.cd();
 //c3.SetTitle("Weighting Field");
 //det.Draw("WFxy").Draw("COLZ");
 
 //TCanvas c4;
 //c4.cd();
 //c4.SetTitle("Weighting Potential");
 //det.Draw("WP").Draw("COLZ");
}
