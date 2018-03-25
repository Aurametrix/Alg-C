class GenericReactor {
  virtual void react(const Event& ev) = 0;
}

//Listing 1
std::unique_ptr r = reactorFactory.createReactor(...);
while(true) { //event loop
  Event ev = get_event();
  //from select(), libuv, ...
  r->react(ev);
}

class SpecificReactor : public GenericReactor {
  void react(const Event& ev) override;
};
