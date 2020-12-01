<template>
  <div class="view_container">
    <h2>{{ experiment.name }}</h2>
    <div id="intro">{{ experiment.introduction }}</div>
    <br>
    <h3 class="list_title">Procedimiento</h3>
    <v-row>
      <v-col>
        <ul class="list">
          <li class="list_item" v-for="item in experiment.instructions" :key="item">{{ item }}</li>
        </ul>
      </v-col>
      <v-col>
      <div class="video_container">
        <video width="420" autoplay controls>
          <source :src="'./videos/' + experiment.videoName" type="video/mp4" />
        </video>
        <video width="420" autoplay controls>
          <source :src="'./videos/' + experiment.videoName2" type="video/mp4" />
        </video>
      </div>
      </v-col>
    </v-row>
  </div>
</template>

<script>
import {mapGetters} from 'vuex'
export default {
  name: "Experiment",
  methods: {
  },
  computed: {
    ...mapGetters({
      experiment: 'getExperiment'
    })
  }
};
</script>
<style scoped>
.view_container {
  justify-content: flex-start !important;
  padding: 100px;
}
.list {
  text-align: left;
}
#intro{
  white-space:pre;
}
</style>
