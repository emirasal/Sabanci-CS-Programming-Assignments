import React, { useEffect, useState } from "react";
import { Link, useLocation, useNavigate } from "react-router-dom";
import newRequest from "../../utils/newRequest";
import "./Navbar.scss";

function Navbar() {
  const [active, setActive] = useState(false);
  const [open, setOpen] = useState(false);

  const { pathname } = useLocation();

  const isActive = () => {
    window.scrollY > 0 ? setActive(true) : setActive(false);
  };

  useEffect(() => {
    window.addEventListener("scroll", isActive);
    return () => {
      window.removeEventListener("scroll", isActive);
    };
  }, []);


  const currentUser = JSON.parse(localStorage.getItem("currentUser"));

  const navigate = useNavigate();

  const handleLogout = async () => {
    try {
      await newRequest.post("/auth/logout");
      localStorage.setItem("currentUser", null);
      navigate("/");
    } catch (err) {
      console.log(err);
    }
  }

  return (
    <div className={active || pathname !== "/" ? "navbar active" : "navbar"}>
      <div className="container">
        <div className="logo">
          <Link className="link" to="/">
            <span className="text" >MediaMatch</span>
          </Link>
          
        </div>
        <div className="links">
          <span>MediaMatch Business</span>
          <Link to="/gigs" className="link">Explore</Link>
          
          {!currentUser?.isSeller && <span>Sell your service </span>}
          {currentUser ? (
            <div className="user" onClick={()=>setOpen(!open)}>
              <img
                src={currentUser.img}
                alt=""
              />
              <span>{currentUser?.username}</span>
              {open && <div className="options">
                {currentUser.isSeller && (
                  <>
                    <Link className="link" to="/mygigs">
                      Services
                    </Link>
                    <Link className="link" to="/add">
                      Add New Service
                    </Link>
                  </>
                )}
                <Link className="link" to="/orders">
                  My Orders
                </Link>
                <Link className="link" to="/messages">
                  Messages
                </Link>
                <Link className="link" onClick={handleLogout}>
                  Logout
                </Link>
              </div>}
            </div>
          ) : (
            <>
              <Link to="/login" className="link">Sign in</Link>
              <Link className="link" to="/register">
                <button>Sign Up</button>
              </Link>
            </>
          )}
        </div>
      </div>
      {(active || pathname !== "/") && (
        <>
          <hr />
          <div className="menu">
            <Link className="link menuLink" to="/">
              Design & Thumbnail
            </Link>
            <Link className="link menuLink" to="/">
              Video Editing
            </Link>
            <Link className="link menuLink" to="/">
              Scriptwriting
            </Link>
            <Link className="link menuLink" to="/">
              Voiceover & Dubbing
            </Link>
            <Link className="link menuLink" to="/">
              Account Managament
            </Link>
            <Link className="link menuLink" to="/">
              Social Media Consulting
            </Link>

          </div>
          <hr />
        </>
      )}
    </div>
  );
}

export default Navbar;
