const fs = require('fs');

const promise = async () => await fs.promises.readFile('./data.json');

(
    async () => {
        const json = JSON.parse(await promise());
        const data = json.data;
        const fields = Object.keys(data[0]);
        
        const replacer = (key, value) => value === null ? '' : value

        let csv = data.map(row => fields.map(fieldName => JSON.stringify(row[fieldName], replacer)).join(','));

        csv.unshift(fields);
        csv = csv.join('\r\n');

        console.log(csv);

        fs.writeFile('results.csv', csv, (error) => {
            if (error) throw error;
            console.log('File created');
        })
    }
)()