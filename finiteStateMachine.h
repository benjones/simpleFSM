#ifndef _FINITE_STATE_MACHINE_H
#define _FINITE_STATE_MACHINE_H

#include<functional>
#include<vector>

class FiniteStateMachine{
  
public:
  class FSMState{
  public:
    
	FSMState(std::function<bool()>&& update_) : _update(std::move(update_)) {}
    
    bool update(){return _update();}
  private:
    std::function<bool()> _update;
  };
  
  FiniteStateMachine(std::vector<FSMState>&& _states) : currentState{0}, states{std::move(_states)} 
  {}
  void reset(){currentState = 0;}
  void update(){
    if(states[currentState].update())
      currentState = (currentState +1)%states.size();
  }
  
private:
  int currentState;
  std::vector<FSMState> states;
};

#endif
