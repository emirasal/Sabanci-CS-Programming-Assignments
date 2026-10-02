import User from "../models/user.js";
import bcrypt from "bcrypt";
import jwt from "jsonwebtoken";
import createError from "../utils/createError.js";

export const register = async (req, res, next) =>{
    
    try {
        const hashhedPassword = await bcrypt.hash(req.body.password, 7);
        const newUser = new User({
            ...req.body,
            password: hashhedPassword,
        });

        await newUser.save();
        res.status(201).send("User has been created.");

    } catch(err) {
        next(err);
    }
} 

export const login = async (req, res, next) =>{
    
    try {
       const user = await User.findOne({username:req.body.username});
    

       if (!user) return next(createError(404, "No such user"));

        const isCorrect = bcrypt.compareSync(req.body.password, user.password);
        if (!isCorrect) next(createError(400, "Wrong credidentials."));


        const token = jwt.sign({
            id:user._id, 
            isSeller: user.isSeller,
        }, process.env.JWT_KEY
        );

        const {password, ...info} = user._doc;
        res.cookie("accessToken", token, {
            httpOnly: true
        }).status(200).send(info);

    } catch(err){
            next(err);
        }
}

export const logout = async (req, res) =>{
    
    try {
        res.clearCookie("accessToken", {
            sameSite:"none",
            secure: true,
        }).status(200).send("User is logged out.");
    } catch(err) {
        next(err);
    }
}