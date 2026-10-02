import React from 'react';
import Productlisting from './Productlisting';
import LoginRegister from './LoginRegister';

function Home() {
  const userToken = localStorage.getItem('userId');

  return (
    <div>
      {userToken ? <Productlisting/> : <LoginRegister/>}
    </div>
  );
}

export default Home;