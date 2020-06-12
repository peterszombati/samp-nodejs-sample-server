import {OnPlayerConnect} from "samp-node-lib";

OnPlayerConnect(player => {
    player.SendClientMessage('rgba(104,160,99,1)', "Node.js running");
});
