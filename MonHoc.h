#pragma once
#include"Struct.h"
#include<string>
#define MAX_MONHOC 300

struct MONHOC {
	string MaMH;
	string TenMH;
};
struct List_MONHOC {
	int n;
	MONHOC nodeMONHOC[MAX_MONHOC];
};
typedef List_MONHOC DSMH;
bool isEmpty(DSMH dsMonHoc) {
	return (dsMonHoc.n == 0);
}
bool isFull(DSMH dsMonHoc) {
	return (dsMonHoc.n == MAX_MONHOC);
}
void createDSMH(DSMH& dsMonHoc) {
	dsMonHoc.n = 0;
}
void printMonHoc(DSMH dsMonHoc) {
	for (int i = 0; i < dsMonHoc.n; i++) {
		cout << "Ma mon hoc: " << dsMonHoc.nodeMONHOC[i].MaMH << "   ";
		cout << "Ten mon hoc: " << dsMonHoc.nodeMONHOC[i].TenMH << endl;
	}
}
bool ktMa(DSMH dsMonHoc, string Ma) {
	for (int i = 0; i < dsMonHoc.n; i++) {
		if (dsMonHoc.nodeMONHOC[i].MaMH == Ma)return true;
	}
	return false;
}
int positionMa(DSMH dsMonHoc, string Ma) {
	for (int i = 0; i < dsMonHoc.n; i++) {
		if (dsMonHoc.nodeMONHOC[i].MaMH == Ma)return i;
	}
	return -1;
}
void addMonHoc(DSMH& dsMonHoc) {
	string MaMH;
	cout << "Nhap ma mon hoc: ";
	cin >> MaMH;
	if (isFull(dsMonHoc)) {
		cout << "Danh sach da day" << endl;
		return;
	}
	while (ktMa(dsMonHoc, MaMH)) {
		cout << "Ma mon hoc da trung, hay nhap lai ma moi: ";
		cin >> MaMH;
		cout << endl;
	}
	dsMonHoc.nodeMONHOC[dsMonHoc.n].MaMH = MaMH;
	string TenMH;
	cout << "Nhap ten mon hoc: ";
	cin.ignore();
	getline(cin,TenMH);
	dsMonHoc.nodeMONHOC[dsMonHoc.n].TenMH = TenMH;
	dsMonHoc.n++;
	cout << endl;
}
void deleteMonHoc(DSMH& dsMonHoc) {
	if (isEmpty(dsMonHoc)) {
		cout << "Danh sach trong" << endl;
		return;
	}
	string MaMH;
	cout << "Nhap ma mon hoc can xoa: ";
	cin >> MaMH;
	for (int i = 0; i < dsMonHoc.n; i++) {
		if (dsMonHoc.nodeMONHOC[i].MaMH == MaMH) {
			for (int j = i; j < dsMonHoc.n - 1; j++) {
				dsMonHoc.nodeMONHOC[j] = dsMonHoc.nodeMONHOC[j + 1];
			}
		}
	}
	dsMonHoc.n--;
}
//void adjustInfo_MonHoc(DSMH& dsMonHoc) {
//	string MaMH;
//	cout << "Nhap ma mon hoc can xoa: ";
//	cin >> MaMH;
//	if (ktMa(dsMonHoc, MaMH));
//}


