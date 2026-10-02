import React from "react";
import "./Gig.scss";
import { Slider } from "infinite-react-carousel/lib";
import { useParams } from "react-router-dom";
import { useQuery } from "@tanstack/react-query";
import newRequest from "../../utils/newRequest";
import Reviews from "../../components/reviews/Reviews";


function Gig() {

  const {id} = useParams();


  const { isLoading, error, data } = useQuery({
    queryKey: ["gig"],
    queryFn: () =>
      newRequest.get(`/gig/getGig/${id}`).then((res) => {
        return res.data;
      }),
  });


  const { isLoading: isLoadingUser, error: errorUser, data: dataUser } = useQuery({
    queryKey: ["user"],
    queryFn: () =>
      newRequest.get(`/user/${data.userId}`).then((res) => {
        return res.data;
      }),
  });



  const onContinueClick = async () => {

    try {
      const response = await fetch(`http://localhost:8800/backend/orders/${id}`, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        // Add any additional headers if needed
      },
      // If you need to send any data in the request body, you can do so here
      body: JSON.stringify({
        // Your request body data here, if any
      }),
      credentials: 'include', // Include cookies with the request
    });

      if (!response.ok) {
        console.error('Failed');
      }
      
    } catch (error) {
      // Handle any unexpected errors
      console.error('Error:', error);
    }

  };

  return (
    <div className="gig">
      {isLoading ? "loading" : error ? "Something went wrong." : <div className="container">
        <div className="left">
          <span className="breadcrumbs">Liverr {">"} Graphics & Design {">"}</span>
          <h1>{data.title}</h1>
          {isLoadingUser ? "loading" : errorUser ? "Something went wrong" : <div className="user">
            <img
              className="pp"
              src={dataUser.img || "/img/noavatar.jpg"}
              alt=""
            />
            <span>{dataUser.username}</span>
            {!isNaN(data.totalStars / data.starNumber) && (
                  <div className="stars">
                    {Array(Math.round(data.totalStars / data.starNumber))
                      .fill()
                      .map((item, i) => (
                        <img src="/img/star.png" alt="" key={i} />
                      ))}
                    <span>{Math.round(data.totalStars / data.starNumber)}</span>
                  </div>
                )}
          </div>}
          <Slider slidesToShow={1} arrowsScroll={1} className="slider">
            {data.images.map(img => (
              <img
              key={img}
              src={img}
              alt=""
            />
            ))}
          </Slider>
          <p>
            {data.desc}
          </p>
          {isLoadingUser ? "loading" : errorUser ? "Something went wrong" : <div className="seller">
            <h2>About The Seller</h2>
            <div className="user">
              <img
                src={dataUser.img || "/img/noavatar.jpg"}
                alt=""
              />
              <div className="info">
                <span>{dataUser.username}</span>
                {!isNaN(data.totalStars / data.starNumber) && (
                  <div className="stars">
                    {Array(Math.round(data.totalStars / data.starNumber))
                      .fill()
                      .map((item, i) => (
                        <img src="/img/star.png" alt="" key={i} />
                      ))}
                    <span>{Math.round(data.totalStars / data.starNumber)}</span>
                  </div>
                )}
                <button>Contact Me</button>
              </div>
            </div>
            <div className="box">
              <div className="items">
                <div className="item">
                  <span className="title">From</span>
                  <span className="desc">{dataUser.country}</span>
                </div>
                <div className="item">
                  <span className="title">Member since</span>
                  <span className="desc">Aug 2022</span>
                </div>
                <div className="item">
                  <span className="title">Avg. response time</span>
                  <span className="desc">4 hours</span>
                </div>
                <div className="item">
                  <span className="title">Last delivery</span>
                  <span className="desc">1 day</span>
                </div>
                <div className="item">
                  <span className="title">Languages</span>
                  <span className="desc">English</span>
                </div>
              </div>
              <hr />
              <p>
                {dataUser.desc}
              </p>
            </div>
          </div>}
          <Reviews gigId={id}/>
        </div>
        <div className="right">
        <h2>About This Service</h2>
          <p>
           {data.desc}
          </p>
          <div className="price">
            <h3>{data.shortTitle}</h3>
            <h2>$ {data.price}</h2>
          </div>
          <p>
            {data.shortDesc}
          </p>
          <div className="details">
  <div className="card item">
    <img src="/img/clock.png" alt="" />
    <span>{data.deliveryDate} Days Delivery</span>
  </div>
  <div className="card item">
    <img src="/img/recycle.png" alt="" />
    <span>{data.revisionNumber} Revisions</span>
  </div>
</div>
<div className="features">
  {data.features.map(feature => (
    <div className="card item" key="feature">
      <img src="/img/bluecheckmark.png" alt="" />
      <span>{feature}</span>
   </div>
  ))}

</div>

          <a href="/orders"><button onClick={onContinueClick}>Continue</button></a>
        </div>
      </div>}
    </div>
  );
}

export default Gig;
