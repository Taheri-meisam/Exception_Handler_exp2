
#include <stdio.h>
#include <exception>
#include <iostream>
#include <unistd.h>
using namespace std;
class check_exception : exception {
private:
	int health;
	public :
	const char* what() {
		return " Game over ... " ;
	}
	void get_health() {
		cout <<  " the health level is " << health <<endl;
	}
	
	void set_health( int SetHealth) {
		this->health = SetHealth;
	}
};
class GameObject_health {
	private :
	int health;
	public :
	GameObject_health(){
		health = 10;
		cout << " The current health Level is "<< health <<endl;
	}
	void  health_calc() {
		while(true){
			sleep(1);
				//health -=1;
			health = random() % 10;
			cout << " The health is :" << health <<endl;
			if (health == 0) {
				check_exception chx;
				chx.set_health(health);
				throw chx;
			}
		}
	}
};
int main(int agvc, char **argv){
	GameObject_health gh;
	try{
		gh.health_calc();
		
	}catch(check_exception ch_x){
		cout << ch_x.what() << endl;
		ch_x.get_health();
	}
	return(EXIT_SUCCESS);
}
