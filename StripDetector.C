{
 TF3 *f2=new TF3("f2","[0]",0,3000,0,3000,0,3000);
 f2->SetParameter(0,-5.6);

 KStrip *det=new KStrip(7840,7183,3,1,300);
 det->Voltage=-100;
 det->SetUpVolume(2);
 det->SetUpElectrodes();
 det->SetBoundaryConditions();
 det->SetUpMaterial(0);
 det->Temperature=253;

 det->NeffF=f2;
 det.SetDebug(0);
 det.CalField(0);
 det.CalField(1);
 
 Tcanvas c5:
 det->SetEntryPoint(400, 200, 0.5);
 det->SetExitPoint(7500,200,0.5);
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
