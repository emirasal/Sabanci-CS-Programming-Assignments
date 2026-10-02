import mongoose from "mongoose";

const dbConnect = () => {
    //const connectionParams = {useNewUrlParser:true};
    //mongoose.connect(process.env.DB, connectionParams);
    mongoose.connect("mongodb+srv://emirasal:Emirasal3@cluster0.arp2ew3.mongodb.net/");

    mongoose.connection.on("connected", ()=> {
        console.log("Connected to database");
    });

    mongoose.connection.on("error", (err)=>{
        console.log("Database connection error");
    });

};

export default dbConnect;