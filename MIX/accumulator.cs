template<typename T>
                      struct Acc {
                        Acc(T n)
                        : n(n) {}

                        template<typename U>
                        Acc(const Acc<U>& u)
                        : n(u.n) {}

                        template<typename U>
                        T operator()(U i) {
                            return n += i;
                        }

                        T n;
                      };
