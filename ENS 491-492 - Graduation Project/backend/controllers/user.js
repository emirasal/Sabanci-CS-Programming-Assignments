import User from "../models/user.js";


export const deleteUser = async (req, res, next) =>{

    const user = await User.findById(req.params.id);
    
    if (req.userId !== user._id) {
        next(403, "You do not have permission to delete");
    }
    await user.findByIdAndDelete(req.param.id);
    res.status(200).send("User has been deleted");
};

export const getUser = async (req, res, next) =>{
    const user = await User.findById(req.params.id);
    res.status(200).send(user);
};