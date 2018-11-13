#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "product.h"

class Order
{
  public:
    Order();
    int order_number();
    void add_product(Product *product);
    bool paid();
    void pay();
    bool filled();
    void fill();

  protected:
    std::vector<Product *> _products;

  private:
    int _next_order_number;
    int _order_number;
    bool _is_paid;
    bool _is_filled;
};
#endif