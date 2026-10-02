import React, { useState } from 'react';
import CheckoutForm from './Form';
import Cart from './Cart';
import './Form.css';

function Checkout() {
  const [cartData, setCartData] = useState(null);

  return (
    <div className='checkout'>
      <Cart setCartData={setCartData} />
      <CheckoutForm cartData={cartData} />
    </div>
  );
}

export default Checkout;