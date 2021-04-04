{
 TF3 *f2=new TF3("f2","[0]",0,3000,0,3000,0,3000);   
 f2->SetParameter(0,-5.6);

 KStrip *det=new KStrip(7840,7183,3,1,300);      //Setup diode dimensions and embedded n-doped region dimensions
 det->Voltage=-100;                             //Setup voltage 
 det->SetUpVolume(2);                           //Generate diode volume
 det->SetUpElectrodes();                        //generate electrodes
 det->SetBoundaryConditions();                  //generate boundary conditions
 det->SetUpMaterial(0);            //Generate Silicon diode
 det->Temperature=253;             //Set temperature to 253K (-20 deg)

 det->NeffF=f2;                    //Set effective doping of n-region to f2
 det.SetDebug(0);                 
 det.CalField(0);                  //calculate electric field
 det.CalField(1);                  //calculate ramo field 
 
 Tcanvas c5:                              //generate plotting canvas
 det->SetEntryPoint(400, 200, 0.5);       //Set entryp oint for electron-hole generation
 det->SetExitPoint(7500,200,0.5);         //set exit point for electron-hole generation
 det->diff=1;                             //turn diffusion on
 det->ShowMipIR(100);                     //show drift paths of 100 electron-hole pairs
 
 TCanvas c1;
 c1.cd();
 c1.SetTitle("Electric Field");
 det.Draw("EFxy").Draw("COLZ");	//Draw("EFxy", 60) for z=60um      //plot electric field in the xy plane
 
 TCanvas c2;
 c2.cd();
 c2.SetTitle("Electric Potential");                               //plot electric potential in the xy plane
 det.Draw("EP").Draw("COLZ");
 
 //TCanvas c3;
 //c3.cd();
 //c3.SetTitle("Weighting Field");
 //det.Draw("WFxy").Draw("COLZ");            //plot weighting field in the xy plane
 
 //TCanvas c4;
 //c4.cd();
 //c4.SetTitle("Weighting Potential");
 //det.Draw("WP").Draw("COLZ");             //plot weighting potential in the xy plane
}
