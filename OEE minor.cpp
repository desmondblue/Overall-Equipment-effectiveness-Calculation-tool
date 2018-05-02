// #include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int shut_Down_Losses();
int down_Time_Losses();
int performance_Losses();
int defect_Losses();
int Down_Time_Analysis(int a, int b);
int main()
{
     float Total_Time,Loading_Time,Total_Shut_Down_Losses,Total_Down_Time_Losses,Operating_Time;
     float Total_Performance_Losses,Net_Operating_Time,Total_Defect_Losses,Value_Operating_Time;
     float Capacity_Utilization=0,mtbf,Actual_Production,Standard_Manpower_Productivity;
     float ar,pr,qr,oee,Unaccounted_Time,Target_Production,Std_Manpower,Actual_Manpower_Deployed;
     float Good_Product,Reject_Product,cvot,Machine_Productivity,Manpower_Deployed;
     float Actual_Manpower_Productivity,Speed;
     string s,m;
     stringstream ss;
     cout<<"Overall Equipment Effectiveness Calculation tool\n";
     cout<<"\nCompany Name: ";
     getline(cin,s);
     ss<<s;
     cout<<"Machine Name: ";
     getline(cin,m);
     ss<<m;
     cout<<"Enter Speed: ";
     cin>>Speed;
     cout<<"TOTAL TIME in minute: ";
     cin>>Total_Time;
        Total_Shut_Down_Losses=shut_Down_Losses();
     cout<<"\n\nTOTAL SHUTDOWN LOSS in minute: "<<Total_Shut_Down_Losses;
     Loading_Time=Total_Time-Total_Shut_Down_Losses; //Calculation of Loading time
     cout<<"\nLOADING TIME : "<<Loading_Time;
     Total_Down_Time_Losses=down_Time_Losses();     //Calculation of down time losses
     cout<<"\nTOTAL DOWN TIME LOSS : "<<Total_Down_Time_Losses;
     Operating_Time=Loading_Time-Total_Down_Time_Losses;    //Calculation of Operating time
     cout<<"\nOPERATING TIME: "<<Operating_Time;
     Total_Performance_Losses=performance_Losses();         //Calculation of Performance loss
     cout<<"\nTOTAL PERFORMANCE LOSS: "<<Total_Performance_Losses;
     Net_Operating_Time=Operating_Time-Total_Performance_Losses; // Calculation of net operating time
     cout<<"\nNET OPERATING TIME : "<<Net_Operating_Time;
     Total_Defect_Losses=defect_Losses();                   //Calculation of Total Defect losses
     cout<<"\nTOTAL DEFECTS LOSS: "<<Total_Defect_Losses;
     Value_Operating_Time=Net_Operating_Time-Total_Defect_Losses;
     cout<<"\nVALUE OPERATING TIME : "<<Value_Operating_Time;
     Capacity_Utilization=(Loading_Time*100)/Total_Time;
     cout<<"\n\nCapacity Utilization: "<<Capacity_Utilization<<"%";
     Down_Time_Analysis(Loading_Time,Total_Down_Time_Losses);
     cout<<"\nVolume produced Good: ";
     cin>>Good_Product;
     cout<<"\nVolume produced Reject:";
     cin>>Reject_Product;
     pr=((Good_Product+Reject_Product)/Speed)/Operating_Time;   //Performance Rate
     ar=Operating_Time/Loading_Time;                            //Availability Rate
     qr=Good_Product/(Good_Product+Reject_Product);             //Quality Rate
     oee=ar*pr*qr*100;                                  //OEE SCORE
     cout<<"\npr"<<pr;
     cout<<"\nar"<<ar;
     cout<<"\nqr"<<ar;
     cout<<"\n\nOEE is "<<oee<<"%";
     cvot=(Good_Product+Reject_Product)/Speed;
     cout<<"\nCVOT: "<<cvot;
     Unaccounted_Time=Value_Operating_Time-cvot;
     cout<<"\nUn-Accounted Time: "<<Unaccounted_Time;
     Actual_Production=Good_Product+Reject_Product;
     cout<<"\nActual Production: "<<Actual_Production;
     cout<<"\nStd. Manpower: ";
     cin>>Std_Manpower;
     cout<<"\nManpower Deployed: ";
     cin>>Manpower_Deployed;
     Actual_Manpower_Deployed=(Manpower_Deployed/Std_Manpower);
     cout<<"Actual_Manpower_Deployed= "<<Actual_Manpower_Deployed;
     Standard_Manpower_Productivity=(Loading_Time*Speed)/Std_Manpower;
     cout<<"Standard_Manpower_Productivity= "<<Standard_Manpower_Productivity;
     Actual_Manpower_Productivity=Actual_Production/Actual_Manpower_Deployed;
     Target_Production = Speed*Loading_Time*Actual_Manpower_Deployed;
     Machine_Productivity=((Actual_Production/Target_Production)*100);
     cout<<"\nActual Manpower Productivity: "<<Actual_Manpower_Productivity;
     cout<<"\nTarget Production"<<Target_Production;
     cout<<" \nMachine Productivity: "<< Machine_Productivity;
     getch();
}

int shut_Down_Losses()
{
     int hdt,psdt,pmt,pbt,pmaint,osdlt,tsdl=0;
     cout<<"\n\nSHUTDOWN LOSSES";
     cout<<"\n\tHolidays Holidays in minute:";
     cin>>hdt;
     cout<<"\n\tPlanned Shutdown in minute:";
     cin>>psdt;
     cout<<"\n\tPlanned Modification in minute :";
     cin>>pmt;
     cout<<"\n\tPlanned Maintenance in minute:";
     cin>>pmaint;
     cout<<"\n\tPlanned Break in minute:";
     cin>>pbt;
     cout<<"\n\tOther Shutdown Losses in minute:";
     cin>>osdlt;
     tsdl=hdt+psdt+pmt+pmaint+pbt+osdlt;
     return tsdl;
}
int down_Time_Losses()
{
     int ebdet,ebdmt,ebdct,ebdot,copct,coprct,colst,cbct,tdtl=0;
     int surdt,utility_Lose,Management_Loss,Operational_Motion;
     cout<<"\n\nDOWNTIME LOSSES";
     cout<<"\n\tEquipment Breakdown Electrical / instrumentation in minute:";
     cin>>ebdet;
     cout<<"\n\tEquipment Breakdown Mechanical in minute:";
     cin>>ebdmt;
     cout<<"\n\tEquipment Breakdown Coding machine in minute :";
     cin>>ebdct;
     cout<<"\n\tEquipment Breakdown Other stoppages in minute:";
     cin>>ebdot;
     cout<<"\n\tChangeovers Pack Change over in minute:";
     cin>>copct;
     cout<<"\n\tChangeovers Product Change over in minute:";
     cin>>coprct;
     cout<<"\n\tChangeovers Line Sanitation in minute:";
     cin>>colst;
     cout<<"\n\tCutting Blade Change in minute:";
     cin>>cbct;
     cout<<"\n\tStart-up/Ramp Down in minute:";
     cin>>surdt;
     cout<<"\n\t Utility Loss in minute:";
     cin>>utility_Lose;
     cout<<"\n\tManagement Loss in minute:";
     cin>>Management_Loss;
     cout<<"\n\tOperational Motion in minute:";
     cin>>Operational_Motion;
     tdtl=ebdet+ebdmt+ebdct+ebdot+copct+coprct+colst+cbct+tdtl+surdt+utility_Lose+Management_Loss+Operational_Motion;
     return tdtl;
}

// Performance Losses
int performance_Losses()
{
     int mst,slt,losct,lonmpt,ft,tpl;
     cout<<"\n\nPERFORMANCE LOSSES";
     cout<<"\n\tMinor Stoppages in minute: ";
     cin>>mst;
     cout<<"\n\tSpeed Loss in minute: ";
     cin>>slt;
     cout<<"\n\tLine Organisation (Shift change) in minute: ";
     cin>>losct;
     cout<<"\n\tLine Organisation (No Manpower/Absentisam) in minute: ";
     cin>>lonmpt;
     cout<<"\n\tFactory(RM/PM stock Out) in minute: ";
     cin>>ft;
     tpl=mst+slt+losct+lonmpt+ft;
     return tpl;
}

int defect_Losses()
{
     int drt,mat,tdl;
     cout<<"\n\nDEFECT LOSSES";
     cout<<"\n\tDefects & Rework(Quality rework) in minute: ";
     cin>>drt;
     cout<<"\n\tMeasurement & Adjustment(Running Weight adjustment) in minute: ";
     cin>>mat;
     tdl=drt+mat;
     return tdl;
}


int Down_Time_Analysis(int a, int b)
{
     int mtbf,mttr;
     cout<<"\nTotal Nos. of Equipment Break Down: "<<"1";
     cout<<"\nTotal Equipment Break Down Time: "<<b;
     mtbf=(a-b)/1;
     cout<<"\nMTBF(Mean Time Between Failure): "<<mtbf;
     cout<<"\nMTTR (Mean Time To Repair) : "<<mttr;
}
