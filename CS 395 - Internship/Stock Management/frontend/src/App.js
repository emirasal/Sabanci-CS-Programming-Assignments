import React from "react";
import Navbar from "./components/navbar";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import Checkout from "./components/Checkout";
import Home from "./components/pages/Home";

function App() {  
  return (
    <div className="App">
      <Router>
        <Navbar />
        <Routes>
          <Route path="/" element={<Home/>} />
          <Route path="/checkout" exact element={<Checkout/>}></Route>
        </Routes>
      </Router>
    </div>
  );
}

export default App;
