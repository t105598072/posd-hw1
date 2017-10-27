#include "list.h"


List::List(): _elements(){}
List::List(vector<Term *> const & elements):_elements(elements){}

string List::symbol() const{
 	string l_brack = "[";
 	string r_brack = "]";
 	string interval = ", ";
 	string content = "";  	

 	if(!_elements.empty()){ 		
 		content += l_brack;
 		for(int i=0; i<_elements.size();i++){
 			if(i!=_elements.size()-1){
 				content += _elements[i]->symbol();
 				content +=interval;
		}
		else
			content += _elements[i]->symbol();
 		}
 		content += r_brack;
 		return content;
 	}
 	else
 	{
 		return l_brack+r_brack;
 	}
}
string List::value() const{return _symbol;}
bool List::match(Term & term){return false;}

bool List::match(List &list){
  if(list._elements.size() == _elements.size()){
    for(int i=0; i<_elements.size();i++){
    }
  }

}

Term * List::head() const{}
List * List::tail() const{}

/*
bool matchToVariable(Variable &var){    
  int key = 0;
  for(int i=0; i<_elements.size();i++){
    if(_elements[i]->symbol()==var->symbol()){
      key++;
    }
    if(key!=0){
      return false;
    }
  var->match(Term &term);
}
*/