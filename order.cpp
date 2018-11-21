#include "order.h"

int Order::orderid = 0;
Order::Order() : _is_paid{false}, _is_filled{false}, _is_discarded{false} { _order_number = orderid++; }

//GETTER METHODS
int Order::order_number() const { return _order_number; }
bool Order::filled() { return _is_filled; }
bool Order::paid() { return _is_paid; }
bool Order::discarded() { return _is_discarded; }

//STATE MACHINE METHODS
void Order::pay(){ if (!_is_paid && !_is_discarded) _is_paid = true; else throw std::runtime_error("Order could not be paid."); }
void Order::fill() { if (!_is_filled && !_is_discarded) _is_filled = true; else throw std::runtime_error("Order could not be filled."); }
void Order::discard() { if(!_is_discarded && !completed()) _is_discarded = true; else throw std::runtime_error("Order could not be discarded."); }
bool Order::pending() { if (!_is_discarded && !_is_paid && !_is_filled) return true; throw std::runtime_error("Order is not pending.");}
bool Order::completed() { if (_is_filled && _is_paid && !_is_discarded) return true; throw std::runtime_error("Order is not completed."); }

//runs through products vector to get profit for each product and adds them up
double Order::profit() { int profit{0}; for (auto i : _products) profit += i->profit(); return profit; } 
void Order::add_product(Product *product) { _products.push_back(product); }

std::string Order::products_to_string()
{
    std::string to_return{""};
    for (auto i : _products)
        to_return += i->to_string() + "\n";
    return to_return;
}

//REQUIRED FOR MAP DATA STRCUTURE
bool operator<(const Order &lord, const Order &rord) { return lord.order_number() < rord.order_number(); }