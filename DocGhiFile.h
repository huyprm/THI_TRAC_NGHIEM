#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"MonHoc.h"
using namespace std;
// Doc file MonHoc.h
void Doc_Thong_Tin_Mon_Hoc(ifstream &fileIn, MONHOC &MH) {
	getline(fileIn, MH.MaMH, '-');
	getline(fileIn, MH.MaMH, '-');
}
void Doc_Danh_Sach_Mon_Hoc(ifstream &fileIn, DSMH& dsMonHoc) {
	fileIn >> dsMonHoc.n;
	MONHOC MH;
	for (int i = 0; i < dsMonHoc.n; i++) {
		Doc_Thong_Tin_Mon_Hoc(fileIn, MH);
		dsMonHoc.nodeMONHOC[i] = MH;
	}
}