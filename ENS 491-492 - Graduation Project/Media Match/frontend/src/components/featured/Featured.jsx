import React, { useState } from "react";
import { useNavigate } from "react-router-dom";
import "./Featured.scss";


function Featured() {
  
  const [input, setInput] = useState("");
  const navigate = useNavigate();

  const handleSubmit = () => {
    navigate(`/gigs?search=${input}`);
  };

  const handleKeyPress = (e) => {
    if (e.key === 'Enter') {
      handleSubmit();
    }
  };

  return (
    <div className="featured">
      <div className="container">
        <div className="left">
          <h1>
            Find the best Social Media Services
          </h1>
          <div className="search">
            <div className="searchInput">
              <img src="./img/search.png" alt="" />
              <input 
                type="text" 
                placeholder='Try "video editor"' 
                onChange={(e) => setInput(e.target.value)} 
                onKeyPress={handleKeyPress} 
              />
            </div>
            <button onClick={handleSubmit}>Search</button>
          </div>
          
        </div>
        <div className="right">
          <img src="./img/platforms.png" alt="" />
        </div>
      </div>
    </div>
  );
}

export default Featured;
