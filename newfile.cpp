#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
using namespace std;

class person {
private:
	string name;
	string email;
	int cnic;
public :
	person() {
	}
	person(string n, string e, int id) {
		name = n;
		email = e;
		cnic = id;
	}
	void setname(string n) {
	     name = n;
	}
	void setemail(string e) {
		email = e;
	}
	void setcnic(int id) {
		cnic = id;
	}
	string getname() { return name; }
	string getemail() { return email; }
	int getcnic() { return cnic; }

	void displayperson() {
		cout << "Name : " << name << endl;
		cout << "Email :" << email << endl;
		cout << "CNIC : " << cnic << endl;
		cout << endl;
	}
};
class plant {
private:
	person admin;
	string nameofplant;
public:
	plant(){}
	plant(string n, person ad) {
		nameofplant = n;
		admin = ad;
	}
	void setadmin(string n, string e, int id) {
		admin.setemail(e);
		admin.setname(n);
		admin.setcnic(id);
	}
	person getadmin() {
		return admin;
	}
	void setnameofplant(string n) {
		nameofplant = n;
	}
	string getnameofplant() {
		return nameofplant;
	}
	void getadmindetails() {
		admin.displayperson();
	}
	void getplantdetails() {
		cout << "Name of plant:" << nameofplant;
		cout << "Admin of plant :" << endl; admin.displayperson();
		cout << endl;
	}
	void setadmindirect(person a) {
		admin = a;
	}
};
class regionalstation {
private:
	string nameofstation;
	person director;
	plant south;
	plant north;
	plant west;
public:
	regionalstation(){}
	regionalstation(string np ,person d, plant s, plant n, plant w) {
		director = d;
		south = s;
		west = w;
		north = n;
		nameofstation = np;
	}
	void setdirector(string n, string e, int id) {
		director.setemail(e);
		director.setcnic(id);
		director.setname(n);
	}
	person getdirector() { return director; }

	void setnorthplant(person ad, string n) {
		north.setadmindirect(ad);
		north.setnameofplant(n);
	}
	void setwestplant(person ad, string n) {
		west.setadmindirect(ad);
		west.setnameofplant(n);
	}
	void setsouthplant(person ad, string n) {
		south.setadmindirect(ad);
		south.setnameofplant(n);
	}
	void displaystation() {
		cout << "Regional station:" << nameofstation << endl;
		cout << "Director info :"; director.displayperson();
		north.getplantdetails();
		south.getplantdetails();
		west.getplantdetails();
		cout << endl;
	}

};
class company {
private:
	string nameofcompany;
	person ceo;
	regionalstation one;
	regionalstation two;
	regionalstation three;
	regionalstation four;
	regionalstation five;

public :
	company(){}
	company(string noc, person ceoo, regionalstation o, regionalstation t, regionalstation thr, regionalstation fur, regionalstation fv) {
		nameofcompany = noc;
		one = o;
		two = t;
		three = thr;
		four=fur;
		five = fv;
		ceo = ceoo;
	}
	void displaycompanydetails() {
		cout << "Name of Company :" << nameofcompany << endl;
		cout << "CEO of the Company :"; ceo.displayperson();
		one.displaystation();
		two.displaystation();
		three.displaystation();
		four.displaystation();
		five.displaystation();
		cout << endl;
	}
	~company() {
		cout << "Destructor called";
	}
};


int main() {
	
	person admin1("Inshira", "inshir@gmail.com",12362626);
	person admin2("Mateen", "mateen@gmail.com", 92363529);
	person admin3("Fatima", "infatr@gmail.com",41233325);
	person adminnew("Newadmin", "newe23@gmail.com", 939393);
	plant plant1("NEW PLANT", admin1);
	plant1.setadmindirect(adminnew);
	plant plant2("P", admin2);
	plant plant3("U", admin3);

	person director1("D1", "direct1@gm.com",8759887);
	regionalstation one("one station", director1, plant1, plant2, plant3);
	person director2("D2", "direct2@gm.com", 9864455);
	regionalstation two("two station", director2, plant2, plant1, plant3);
	person director3("D3", "direct3@hh.com", 6547676);
	regionalstation three("three station ", director3, plant3, plant1, plant2);
	person director4("D4", "direct4@hh.com", 6547676);
	regionalstation four("four station ", director4, plant1, plant2, plant3);
	person director5("D5", "direct5@hh.com", 6547676);
	regionalstation five("five station ", director5, plant2, plant1, plant3);
	person ceoone("CEO", "ceo@gmh.com", 42678346);
	company commpanynew("companyone", ceoone, one, two, three, four, five);
	commpanynew.displaycompanydetails();


	return 0;
}

