// Online C++ compiler to run C++ program online
#include <cstdlib>
#include <iostream>
#include <stddef.h>
#include <string>
#include <iomanip>

int main() {
  // Write C++ code here
  int jml_hari, jml_harix, jml_hariz;

  std::cout << "        Menghitung probabilitas       \n";
  std::cout << "Berdasarkan kemungkinan cuaca dan mood\n";
  std::cout << "======================================\n";

  std::cout << "Masukan Jumlah prediksi hari : ";
pre_hari:
  std::cin >> jml_hari;
  std::cout << "\n";
  jml_hariz = jml_hari + 1;

  if (jml_hari > 0) {
    goto awal;
  } else if (jml_hari < 0) {
    jml_hari = 0;
    jml_hariz = 0;
    std::cout << "Angka tidak boleh kurang dari 0\n";
    std::cout << "Masukan Jumlah prediksi hari : ";
    goto pre_hari;
  } else {
    jml_hari = 0;
    jml_hariz = 0;
    std::cout << "Masukan tidak diketahui atau masukan tidak terdefinisi\n";
    std::cout << "Masukan Jumlah prediksi hari : ";
    goto pre_hari;
  }

  // MASUKAN PROPABILITAS HARI
awal:
  std::cout << "        Petunjuk memasukan hari      \n";
  std::cout << "           Ketik R untuk R/Hujan       \n";
  std::cout << "           Ketik S untuk S/Cerah       \n";
  std::cout << "======================================\n\n";
  jml_harix = jml_hari - 1;
  std::string pro_hari;
  std::string pro_harix[100];
  
  std::cout << "Masukan kemungkinan cuaca dalam hari " << jml_hari
            << " adalah \n";
  hari1:
   std::cout<<"1. ";
  std::getline(std::cin, pro_hari);
  if (pro_hari == "R") {
    pro_harix[0] = "R";
    pro_hari = "";
  } else if (pro_hari == "S") {
    pro_harix[0] = "S";
    pro_hari = "";
  } else if (pro_hari.empty()) {
      pro_hari = "";
      std::cout << "Data yang tidak boleh kosong\n";
      goto hari1;
    }else {
    pro_hari = "";
    std::cout << "Data yang dimasukan tidak terdefinisi\n";
    goto hari1;
  }
  int i = 1;
  do {
    int ix = i + 1;
  hari2:
    std::cout << ix << ". ";

    std::getline(std::cin, pro_hari);
    if (pro_hari == "R") {
      pro_harix[i] = "R";
      pro_hari = "";
    } else if (pro_hari == "S") {
      pro_harix[i] = "S";
      pro_hari = "";
    } 
    else if (pro_hari.empty()) {
      pro_hari = "";
      std::cout << "Data yang tidak boleh kosong\n";
      goto hari2;
    } else {
      pro_hari = "";
      std::cout << "Data yang dimasukan tidak terdefinisi\n";
      goto hari2;
    }
    i++;
  } while (i < jml_hari);

  // MASUKAN PROBABILITAS MOOD
  std::cout << "\n          Petunjuk memasukan mood         \n";
  std::cout << "           Ketik G untuk G/Bad Mood       \n";
  std::cout << "            Ketik H untuk H/Senang        \n";
  std::cout << "======================================\n\n";
  jml_harix = jml_hari - 1;
  std::string pro_mood;
  std::string pro_moodx[100];


  std::cout << "Masukan kemungkinan cuaca dalam hari " << jml_hari
            << " adalah \n";
  mood1:
    std::cout<<"1. ";
  std::getline(std::cin, pro_mood);
  if (pro_mood == "G") {
    pro_moodx[0] = "G";
    pro_mood = "";
  } else if (pro_mood == "H") {
    pro_moodx[0] = "H";
    pro_mood = "";
  } else if (pro_mood.empty()) {
      pro_hari = "";
      std::cout << "Data yang tidak boleh kosong\n";
      goto mood1;
    } else {
    pro_mood = "";
    std::cout << "Data yang dimasukan tidak terdefinisi\n";
    goto mood1;
  }
  int j = 1;
  do {
    int jx = j + 1;
  mood2:
    std::cout << jx << ". ";

   std::getline(std::cin, pro_mood);
    if (pro_mood == "G") {
      pro_moodx[j] = "G";
      pro_mood = "";
    } else if (pro_mood == "H") {
      pro_moodx[j] = "H";
      pro_mood = "";
    } else if (pro_mood.empty()) {
      pro_hari = "";
      std::cout << "Data yang tidak boleh kosong\n";
      goto mood2;
    }else {
      pro_mood = "";
      std::cout << "Data yang dimasukan tidak terdefinisi\n";
      goto mood2;
    }
    j++;
  } while (j < jml_hari);
  // Probanilitas yang didapat
  std::cout << "\n Probabilitas yang didapat adalah \n";
  std::cout << "=============================================\n";

  //menampilkan probabilitas hari
  std::cout << "Probabilitas Hari = [";
  int k = 0;
  int R=0,S=0;
  do {
  if (pro_harix[k]== "R") {
     std::cout<<"R ";
    k++;
    R++;
    
    } 
  else if (pro_harix[k] == "S") {
     std::cout<<"S ";
    k++;
    S++;
    } 
  } while (k < jml_hari);
  std::cout<<"]\n";

   //menampilkan probabilitas mood
  std::cout << "Probabilitas Mood = [";
  int l = 0;
  double G=0,H=0;
  do {
  if (pro_moodx[l]== "G") {
     std::cout<<"G ";
    l++;
    G++;
    } 
  else if (pro_moodx[l] == "H") {
     std::cout<<"H ";
    l++;
    H++;
    } 
  } while (l < jml_hari);
  std::cout<<"]\n\n";

  //menghitung probabilitas rainy and shiny
  float RS,GH;
  RS=R+S;
  GH=G+H;
  float pro_r=R/RS;
  float pro_s=S/RS;
  double jml_r=0,jml_s=0;
  std::cout<<"p_s = "<<pro_s<<std::endl;
  std::cout<<"p_r = "<<pro_r<<"\n\n";

  //menghitung probabilitas 2 hari
  int a=0,ax=0;
  double rr=0,rs=0,ss=0,sr=0;
  
 
     amd:
    ax=a+1;
    if(a<jml_hari){
       if(pro_harix[a]=="R"){
          if(pro_harix[ax]=="R"){
            rr++; a++;jml_r++;
            goto amd;
          }
         else if(pro_harix[ax]=="S"){
            rs++; a++;jml_r++;
            goto amd;
          }
    }
    
       else if(pro_harix[a]=="S"){
         if(pro_harix[ax]=="R"){
          sr++; a++;jml_s++;
           goto amd;
        }
         else if(pro_harix[ax]=="S"){
        ss++; a++;jml_s++;
           goto amd;
    }
   
    }}
      else{
        goto awal2;
      }
  
  awal2:
   double pro_rr,pro_rs,pro_ss,pro_sr;
  pro_ss = ss/jml_s;
  pro_sr = sr/jml_s;
  pro_rr = rr/jml_r;
  pro_rs = rs/jml_r;

  //Hasil probabilitas
   std::cout<<"p_ss = "<< std::fixed << std::setprecision(2) <<pro_ss<<std::endl;
   std::cout<<"p_sr = "<< std::fixed << std::setprecision(2) <<pro_sr<<std::endl;
   std::cout<<"p_rs = "<< std::fixed << std::setprecision(2) <<pro_rs<<std::endl;
   std::cout<<"p_rr = "<<std::fixed << std::setprecision(2) <<pro_rr<<"\n\n";
  

  //menghitung probabilitas 2 hari
  int b=0;
  double rg=0,rh=0,sg=0,sh=0;
  double jml_g=0,jml_h=0;
  
 
     amd1:
    if(b<jml_hari){
       if(pro_harix[b]=="R"){
          if(pro_moodx[b]=="G"){
            rg++; b++;jml_g++;
            goto amd1;
          }
         else if(pro_moodx[b]=="H"){
            rh++; b++;jml_g++;
            goto amd1;
          }
    }
    
       else if(pro_harix[b]=="S"){
         if(pro_moodx[b]=="H"){
          sh++; b++;jml_h++;
           goto amd1;
        }
         else if(pro_moodx[b]=="G"){
        sg++; b++;jml_h++;
           goto amd1;
    }
   
    }}
      else{
        goto awal3;
      }

  awal3:
  double pro_sh,pro_sg,pro_rh,pro_rg;
  pro_sh = sh/jml_h;
  pro_sg = sg/jml_h;
  pro_rh = rh/jml_g;
  pro_rg = rg/jml_g;
  
  std::cout<<"p_sh = "<< std::fixed << std::setprecision(2) <<pro_sh<<std::endl;
   std::cout<<"p_sg = "<< std::fixed << std::setprecision(2) <<pro_sg<<std::endl;
   std::cout<<"p_rh = "<< std::fixed << std::setprecision(2) <<pro_rh<<std::endl;
   std::cout<<"p_rg = "<<std::fixed << std::setprecision(2) <<pro_rg<<"\n\n";

  //menghitung hari pertama
  std::string hasil[100];
  int hj=0;
  double hujan=0,cerah=0,hasilx=0,hasil_r=0,hasil_s=0;
  //Mood Happy
  if(pro_moodx[hj]=="H"){
      cerah=pro_s*pro_sh;
      hujan=pro_r*pro_rh;

      if(cerah>hujan){
        hasil[hj]="S";
        hasilx=cerah;
      }
      else if(cerah<hujan){
        hasil[hj]="R";
        hasilx=hujan;
      }
    hasil_r=hujan;
    hasil_s=cerah;
  }
  //Mood Grampy
  else if(pro_moodx[hj]=="G"){
      cerah=pro_s*pro_sg;
      hujan=pro_r*pro_rg;

      if(cerah>hujan){
        hasil[hj]="S";
        hasilx=cerah;
      }
    else if(cerah<hujan){
        hasil[hj]="R";
        hasilx=hujan; 
      }
    hasil_r=hujan;
    hasil_s=cerah;
  }
 
cerah=0;hujan=0;hj=1;
  double cerah2=0,hujan2=0;
  //kemungkinan hasil setelah hari pertama
  std::string hari_ini;
  std::string hari_sebelumnya;
  hasil:
  if(pro_moodx[hj]=="H"){
    //hari ini cerah
    //kemarin Hujan
    cerah=hasil_r*pro_rs*pro_sh;
    //kemarin cerah
    cerah2=hasil_s*pro_ss*pro_sh;

    if(cerah>cerah2){
      hasil_s=cerah;
    }
    else{
      hasil_s=cerah2;
    }
    cerah=0;cerah2=0;
    //hari ini hujan
    //kemarin Hujan
    hujan=hasil_r*pro_rr*pro_rh;
    //kemarin cerah
    hujan2=hasil_s*pro_sr*pro_rh;

    if(hujan>hujan2){
      hasil_r=hujan;
    }
    else{
      hasil_r=hujan2;
    }
    if(hasil_r>hasil_s){
      hasil[hj]="R";
    }
    else{
       hasil[hj]="S";
    }
    hujan=0;hujan2=0;
    hj=hj+1;
    goto hasil;
  }
  else if (pro_moodx[hj]=="G"){
     //hari ini cerah
    //kemarin Hujan
    cerah=hasil_r*pro_rs*pro_sg;
    //kemarin cerah
    cerah2=hasil_s*pro_ss*pro_sg;

    if(cerah>cerah2){
      hasil_s=cerah;
    }
    else{
      hasil_s=cerah2;
    }
    cerah=0;cerah2=0;
    //hari ini hujan
    //kemarin Hujan
    hujan=hasil_r*pro_rr*pro_rg;
    //kemarin cerah
    hujan2=hasil_s*pro_sr*pro_rg;

    if(hujan>hujan2){
      hasil_r=hujan;
    }
    else{
      hasil_r=hujan2;
    }
    if(hasil_r>hasil_s){
      hasil[hj]="R";
    }
    else{
       hasil[hj]="S";
    }
    hujan=0;hujan2=0;
    hj=hj+1;
    goto hasil;
  }
  
  akhir:
   int akhir=0;
  std::cout << "Probabilitas Cuaca = [";
  do{
    std::cout<<hasil[akhir]<<" ";
    akhir++;
  }while(akhir < jml_hari);
  std::cout << "]";
  return 0;
}
