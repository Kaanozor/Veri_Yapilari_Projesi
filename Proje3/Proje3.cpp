
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <chrono>

#define UZUNLUK 68
int dizi1[] =
  { 1064, 1065, 1066, 1067, 1068, 1069, 1070, 1071, 1072, 1073, 1074, 1075,
1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 2001, 2002, 2003, 2004, 2013, 2014,
2015, 3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010, 3011, 3012, 3013,
3014, 3015, 3016, 3017, 3018, 3019, 3020, 3021, 3022, 3023, 3024, 3025, 3026, 3027,
3028, 3029, 3030, 3031, 3032, 3033, 3034, 3035, 3036, 3037, 3038, 3039, 3040, 3041 };
int dizi2[] =
  { 3041, 3040, 3039, 3038, 3037, 3036, 3035, 3034, 3033, 3032, 3031, 3030,
3029, 3028, 3027, 3026, 3025, 3024, 3023, 3022, 3021, 3020, 3019, 3018, 3017, 3016,
3015, 3014, 3013, 3012, 3011, 3010, 3009, 3008, 3007, 3006, 3005, 3004, 3003, 3002,
3001, 2015, 2014, 2013, 2004, 2003, 2002, 2001, 1083, 1082, 1081, 1080, 1079, 1078,
1077, 1076, 1075, 1074, 1073, 1072, 1071, 1070, 1069, 1068, 1067, 1066, 1065, 1064 };
int dizi3[] =
  { 3039, 1074, 3010, 1082, 3016, 3005, 3008, 3014, 3015, 3023, 3025, 2002,
3021, 3035, 1077, 1065, 1069, 1073, 3011, 2004, 3020, 3001, 3030, 1076, 1081, 3031,
3040, 1071, 3013, 3029, 3036, 3027, 3033, 1070, 3038, 1068, 1080, 3037, 2014, 3003,
3007, 1072, 1066, 1083, 2015, 2003, 3018, 3024, 3034, 3009, 3012, 3019, 3028, 1078,
3017, 2001, 1079, 3041, 1067, 2013, 3026, 1064, 3004, 3022, 3006, 1075, 3032, 3002 };


struct Dugum
{
  int veri;
  Dugum *sag;
  Dugum *sol;
};

struct IkiliSiralamaAgaci
{
  Dugum *kok;
  void agacKur (int *);
  void agacKapat ();
};
void koksil (Dugum *);
bool DFS (Dugum *, int);
bool BFS (Dugum *, int);

using namespace std;
int
main ()
{
  int secim, deger;
  cout << "Arama YAPACAGINIZ AGACI SECINIZ (1, 2, 3) :" << endl;
  scanf ("%d", &secim);
  switch (secim)
    {
    case 1:
      IkiliSiralamaAgaci agac1;
      agac1.kok = NULL;
      for (int i = 0; i < UZUNLUK; i++)
	{
	  agac1.agacKur (&dizi1[i]);
	}
      cout << endl;
      cout << "Agac 1 icin arama yontemini seciniz (DFS:1, BFS:2) :" << endl;
      scanf ("%d", &secim);
      if (secim == 1)
	{
	  cout << endl;
	  cout << "Agac 1 uzerinde DFS ile arayacaginiz degeri giriniz:" <<
	    endl;
	  scanf ("%d", &deger);
	  auto case1_dfs_s = std::chrono::high_resolution_clock::now ();
	  bool durum = DFS (agac1.kok, deger);
	  auto case1_dfs_e = std::chrono::high_resolution_clock::now ();
	  if (durum)
	    {
	      cout << endl;
	      cout << "SONUC => VERI BULUNDU" << endl;
	      auto case1_dfs_r =
		std::chrono::duration_cast < std::chrono::microseconds >
		(case1_dfs_e - case1_dfs_s);
	      cout << "GECEN SURE => " << case1_dfs_r.
		count () << " mikro-saniye" << endl;
	    }
	  else
	    cout << "hata";
	}
      else if (secim == 2)
	{
	  cout << endl;
	  cout << "Agac 1 uzerinde BFS ile arayacaginiz degeri giriniz:" <<
	    endl;
	  scanf ("%d", &deger);
	  auto case1_bfs_s = std::chrono::high_resolution_clock::now ();
	  bool durum = BFS (agac1.kok, deger);
	  auto case1_bfs_e = std::chrono::high_resolution_clock::now ();
	  if (durum)
	    {
	      cout << endl;
	      cout << "SONUC => VERI BULUNDU" << endl;
	      auto case1_bfs_r =
		std::chrono::duration_cast < std::chrono::microseconds >
		(case1_bfs_e - case1_bfs_s);
	      cout << "GECEN SURE => " << case1_bfs_r.
		count () << " mikro-saniye" << endl;
	    }
	  else
	    cout << "hata";
	  agac1.agacKapat ();
	  break;
	}
    case 2:
      IkiliSiralamaAgaci agac2;
      agac2.kok = NULL;
      for (int i = 0; i < UZUNLUK; i++)
	{
	  agac2.agacKur (&dizi2[i]);
	}
      cout << endl;
      cout << "Agac 2 icin arama yontemini seciniz (DFS:1, BFS:2) :" << endl;
      scanf ("%d", &secim);
      if (secim == 1)
	{
	  cout << endl;
	  cout << "Agac 2 uzerinde DFS ile arayacaginiz degeri giriniz:" <<
	    endl;
	  scanf ("%d", &deger);
	  auto case2_dfs_s = std::chrono::high_resolution_clock::now ();
	  bool durum = DFS (agac2.kok, deger);
	  auto case2_dfs_e = std::chrono::high_resolution_clock::now ();
	  if (durum)
	    {
	      cout << endl;
	      cout << "SONUC => VERI BULUNDU" << endl;
	      auto case2_dfs_r =
		std::chrono::duration_cast < std::chrono::microseconds >
		(case2_dfs_e - case2_dfs_s);
	      cout << "GECEN SURE => " << case2_dfs_r.
		count () << " mikro-saniye" << endl;
	    }
	  else
	    cout << "hata";
	}
      else if (secim == 2)
	{
	  cout << endl;
	  cout << "Agac 2 uzerinde BFS ile arayacaginiz degeri giriniz:" <<
	    endl;
	  scanf ("%d", &deger);
	  auto case2_bfs_s = std::chrono::high_resolution_clock::now ();
	  bool durum = BFS (agac2.kok, deger);
	  auto case2_bfs_e = std::chrono::high_resolution_clock::now ();
	  if (durum)
	    {
	      cout << endl;
	      cout << "SONUC => VERI BULUNDU" << endl;
	      auto case2_bfs_r =
		std::chrono::duration_cast < std::chrono::microseconds >
		(case2_bfs_e - case2_bfs_s);
	      cout << "GECEN SURE => " << case2_bfs_r.
		count () << " mikro-saniye" << endl;
	    }
	  else
	    cout << "hata";
	}
      agac2.agacKapat ();
      break;

    case 3:
      IkiliSiralamaAgaci agac3;
      agac3.kok = NULL;
      for (int i = 0; i < UZUNLUK; i++)
	{
	  agac3.agacKur (&dizi3[i]);
	}
      cout << endl;
      cout << "Agac 3 icin arama yontemini seciniz (DFS:1, BFS:2) :" << endl;
      scanf ("%d", &secim);
      if (secim == 1)
	{
	  cout << endl;
	  cout << "Agac 3 uzerinde DFS ile arayacaginiz degeri giriniz:" <<
	    endl;
	  scanf ("%d", &deger);
	  auto case3_dfs_s = std::chrono::high_resolution_clock::now ();
	  bool durum = DFS (agac3.kok, deger);
	  auto case3_dfs_e = std::chrono::high_resolution_clock::now ();
	  if (durum)
	    {
	      cout << endl;
	      cout << "SONUC => VERI BULUNDU" << endl;
	      auto case3_dfs_r =
		std::chrono::duration_cast < std::chrono::microseconds >
		(case3_dfs_e - case3_dfs_s);
	      cout << "GECEN SURE => " << case3_dfs_r.
		count () << " mikro-saniye" << endl;
	    }
	  else
	    cout << "hata";
	}
      else if (secim == 2)
	{
	  cout << endl;
	  cout << "Agac 3 uzerinde BFS ile arayacaginiz degeri giriniz:" <<
	    endl;
	  scanf ("%d", &deger);
	  auto case3_bfs_s = std::chrono::high_resolution_clock::now ();
	  bool durum = BFS (agac3.kok, deger);
	  auto case3_bfs_e = std::chrono::high_resolution_clock::now ();
	  if (durum)
	    {
	      cout << endl;
	      cout << "SONUC => VERI BULUNDU" << endl;
	      auto case3_bfs_r =
		std::chrono::duration_cast < std::chrono::microseconds >
		(case3_bfs_e - case3_bfs_s);
	      cout << "GECEN SURE => " << case3_bfs_r.
		count () << " mikro-saniye" << endl;
	    }
	  else
	    cout << "hata";
	}
      agac3.agacKapat ();
      break;

    default:
      break;
    }

}

void
IkiliSiralamaAgaci::agacKur (int *x)
{
  Dugum *node = new Dugum;
  node->veri = *x;
  if (kok == NULL)
    {
      kok = node;
      return;
    }
  queue < Dugum * >p;
  p.push (kok);
  while (!p.empty ())
    {
      Dugum *temp = p.front ();
      p.pop ();
      if (temp->sol == NULL)
	{
	  temp->sol = node;
	  return;
	}
      else if (temp->sag == NULL)
	{
	  temp->sag = node;
	  return;
	}
      else
	{
	  p.push (temp->sag);
	  p.push (temp->sol);
	}
    }

}

bool
DFS (Dugum * node, int x)
{
  bool durum = false;
  stack < Dugum * >y;
  y.push (node);
  while (y.empty () == false)
    {
      Dugum *temp = y.top ();
      if (temp->veri == x)
	{
	  durum = true;
	  return durum;
	}
      y.pop ();
      if (temp->sag != NULL)
	y.push (temp->sag);
      if (temp->sol != NULL)
	y.push (temp->sol);
    }
  return durum;
}

bool
BFS (Dugum * node, int x)
{
  bool durum = false;
  queue < Dugum * >k;
  k.push (node);
  while (!k.empty ())
    {
      Dugum *temp = k.front ();
      k.pop ();

      if (temp->veri == x)
	{
	  durum = true;
	  return durum;
	}

      if (temp->sol != NULL)
	k.push (temp->sol);
      if (temp->sag != NULL)
	k.push (temp->sag);
    }
  return durum;
}

void
IkiliSiralamaAgaci::agacKapat ()
{
  koksil (kok);

}

void
koksil (Dugum * kok)
{
  if (kok == NULL)
    {
      return;
    }
  koksil (kok->sag);
  koksil (kok->sol);
  delete kok;
  kok = nullptr;
  return;
}
