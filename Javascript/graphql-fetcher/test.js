// importing the module
const graphqlfetch = require('./fetcher');

// change the endpoint to your own graphql api endpoint.
// in this example i use fake graphql api by graphqlzero.almansi.me
const endpoint = 'https://graphqlzero.almansi.me/api';

// defining the graphql query
const query =  `
    query {
        post(id: 1) {
            id
            title
            body
        }
    }
`

// example for graphql mutation
const mutation = `
    mutation{
        createPost(input: { title: "Contoh title", body: "Contoh body" }){
            id,
            title,
            body
        }
    }
`

// Test the graphqlfetch with fake graphql api
// Query test
graphqlfetch(endpoint, query).then(res => {
    console.log(res.data);
}).catch(err => console.log(err))


// Mutation test
graphqlfetch(endpoint, mutation).then(res => {
    console.log(res.data);
}).catch(err => console.log(err))