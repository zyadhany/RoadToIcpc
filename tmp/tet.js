function GetStatueFromContest(id, handles=getHandleSet()) {
  
    // fetch statue from codeforces
    const subbmtions = codeforcesApiMethod({'contestId': id, 'asManager':true}, 'contest.status').reverse();
    const statue = [];
    const hist = {};
    
    const statSht = getDataFromSheet('Status')
    const exists = {};
    for (const stat of statuestatSht) {
      const id = stat.id;
      exists[id] = true;
    }
  
    // optmize data
    for (const subbmtion of subbmtions) {
      const stat = {};
      stat.handle = subbmtion.author.members[0].handle;
      const vardict = subbmtion.verdict;
      stat.id = subbmtion.id
  
      if (vardict != 'OK') continue;
      if (!(stat.handle in handles)) continue;
      if (stat.id in exists) continue;
  
      const index = subbmtion.problem.index;
      const name = subbmtion.problem.name;
      stat.problem = `${index}. ${name}`;
  
  
      stat.time = (new Date(subbmtion.creationTimeSeconds * 1000)).toLocaleString();
  
      statue.push(stat);
    }
    
    if (statue.  == 0) {
        // send gui massege
        alert('No new submissions found.');
        return [];
    }

    return statue;
  }
  