import createError from "../utils/createError.js";
import Order from "../models/order.js";
import Gig from "../models/gig.js";

export const createOrder = async (req, res, next) => {
    try {
        const gig = await Gig.findById(req.params.gigId);

        const newOrder = new Order({
            gigId:gig._id,
            img: gig.cover,
            title:gig.title,
            buyerId:req.userId,
            sellerId:gig.userId,
            price:gig.price,
        });

        await newOrder.save();
        res.status(200).send("successful.");
    } catch(err) {
        next(err);
    }
}

export const getOrders = async (req, res, next) => {
    try {

        const orders = await Order.find({
            ...(req.isSeller ? {sellerId: req.userId} : {buyerId: req.userId}),
        });

        res.status(200).send(orders);

    } catch(err) {
        next(err);
    }
}