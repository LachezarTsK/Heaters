
/**
 * @param {number[]} housePositions
 * @param {number[]} heaterPositions
 * @return {number}
 */
var findRadius = function (housePositions, heaterPositions) {
    housePositions.sort((x, y) => x - y);
    heaterPositions.sort((x, y) => x - y);

    let minRadius = 0;
    let indexHeater = 0;

    for (let house of housePositions) {
        while (indexHeater + 1 < heaterPositions.length
                && house - heaterPositions[indexHeater] > heaterPositions[indexHeater + 1] - house) {
            ++indexHeater;
        }
        minRadius = Math.max(minRadius, Math.abs(house - heaterPositions[indexHeater]));
    }

    return minRadius;
};
