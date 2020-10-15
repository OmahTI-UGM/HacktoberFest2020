const axios = require('axios')

async function request(endpoint, query){
    if(typeof endpoint === 'undefined') throw new Error('Endpoint cannot be null');
    if(typeof query === 'undefined') throw new Error('Query cannot be null');
    if(typeof endpoint !== 'string') throw new Error('Endpoint must be a string');
    if(typeof query !== 'string') throw new Error('Query must be a string');


    let body =  { 
        query: query
    }

    let options = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
            'Accept': 'application/json',
        },
    }

    const response = await axios.post(endpoint, body, options)

    return response;
}

module.exports = request;