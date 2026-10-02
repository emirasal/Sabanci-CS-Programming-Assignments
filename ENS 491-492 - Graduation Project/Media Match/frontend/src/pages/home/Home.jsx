import React from "react";
import "./Home.scss";
import Featured from "../../components/featured/Featured";
import Slide from "../../components/slide/Slide";
import CatCard from "../../components/catCard/CatCard";
import ProjectCard from "../../components/projectCard/ProjectCard";
import { cards, projects } from "../../data";

function Home() {
  return (
    <div className="home">
      <Featured />
      
      <div className="features">
      <div className="container">
        <h1 className="features-title">The best marketplace for social media services</h1>
        <div className="features-grid">
          <div className="feature-card">
            <img src="./img/editor.jpg" alt="Find the real talents" className="feature-icon" />
            <h2 className="feature-card-title">Find the real talents</h2>
            <p>Find high-quality social media services provided by the best talents in their field</p>
          </div>
          <div className="feature-card">
            <img src="./img/automation.jpg" alt="Automate your world" className="feature-icon" />
            <h2 className="feature-card-title">Automate your world</h2>
            <p>Hire the best talents to automate your social media presence</p>
          </div>
          <div className="feature-card">
            <img src="./img/satisfaction.png" alt="100% satisfaction" className="feature-icon" />
            <h2 className="feature-card-title">100% satisfaction</h2>
            <p>You will always be matched with satisfying services</p>
          </div>
        </div>
        
      </div>
    </div>
  

      
      
    </div>
  );
}

export default Home;
